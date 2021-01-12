#include<stdio.h>
#include<iostream>
#include <queue>
#include <vector>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[51][51];
int check[51][51];

int TK, N, M, K;
vector<int> v;
vector<int> ans;
void search()
{
	queue<pair<int,int>> q;

	queue<pair<int,int>> q2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1 && check[i][j]!=1)
			{
				q.push(make_pair(i, j));
				check[i][j] = 1;
				while (1)
				{
					pair<int,int> now = q.front();
					q.pop();
					q2.push(now);

					if (arr[now.first - 1][now.second] == 1 && now.first >= 1 && check[now.first - 1][now.second] != 1)
					{
						q.push(make_pair(now.first - 1, now.second));
						check[now.first - 1][now.second] = 1;
					}

					if (arr[now.first + 1][now.second] == 1 && check[now.first + 1][now.second] != 1)
					{
						q.push(make_pair(now.first + 1, now.second));
						check[now.first + 1][now.second] = 1;
					}
					if (arr[now.first][now.second - 1] == 1 && now.second >= 1 && check[now.first][now.second - 1] != 1)
					{
						q.push(make_pair(now.first, now.second - 1));
						check[now.first][now.second - 1] = 1;
					}
					if (arr[now.first][now.second + 1] == 1 && check[now.first][now.second + 1] != 1)
					{
						q.push(make_pair(now.first, now.second + 1));
						check[now.first][now.second + 1] = 1;
					}

					if (q.empty())
					{
						v.push_back(q2.size());
						while (!q2.empty())
						{
							q2.pop();
						}
						break;
					}

				}
			}
		}
	}


}

int main()
{
	scanf("%d", &TK);

	for (int k = 0; k < TK; k++)
	{
		scanf("%d %d %d", &N, &M, &K);

		

		for (int i = 0; i < K; i++)
		{
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);

			arr[temp1][temp2] = 1;
		}


		search();

		ans.push_back(v.size());

		memset(arr, 0, sizeof(arr));

		memset(check, 0, sizeof(check)); 
		v.clear();
		
	}
	for (int i = 0; i < TK; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}