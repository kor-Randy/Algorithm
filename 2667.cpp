#include<stdio.h>
#include<iostream>
#include <queue>
#include <vector>
#include<algorithm>

using namespace std;

int N;

int a[26][26];
int b[26][26];
vector<int> ans;//나올 수 있는 최대의 경우의 수	( (25) ^ 2 ) / 2
int check[26][26];
int count;
int now;

bool compare(int a, int b)
{
	return a < b;
}

void search()
{
	queue<pair<int,int>> q;
	queue<pair<int, int>> q2;
	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == 1 && check[i][j]!=1)
			{
				q.push(make_pair(i,j));
				check[i][j] = 1;

				while (1)
				{
					pair<int, int> now = q.front();
					q.pop();
					q2.push(now);

					if (a[now.first - 1][now.second] == 1 && now.first >= 1 && check[now.first - 1][now.second] != 1)
					{
						q.push(make_pair(now.first - 1, now.second));
						check[now.first - 1][now.second] = 1;
					}

					if (a[now.first + 1][now.second] == 1 && check[now.first + 1][now.second] != 1)
					{
						q.push(make_pair(now.first + 1, now.second));
						check[now.first + 1][now.second] = 1;
					}
					if (a[now.first][now.second - 1] == 1 && now.second >= 1 && check[now.first][now.second - 1] != 1)
					{
						q.push(make_pair(now.first, now.second - 1));
						check[now.first][now.second - 1] = 1;
					}
					if (a[now.first][now.second + 1] == 1 && check[now.first][now.second + 1] != 1)
					{
						q.push(make_pair(now.first, now.second + 1));
						check[now.first][now.second + 1] = 1;
					}


					if (q.empty())
					{
						ans.push_back(q2.size());
						while (!q2.empty())
							q2.pop();

						

						break;
					}

				}

				


			}
		}
	}

	sort(ans.begin(), ans.end(), compare);

	printf("%d", ans.size());

	for (int i = 0; i < ans.size(); i++)
	{
		printf("\n");
		printf("%d", ans[i]);
	}

}

int main()
{
	scanf("%d", &N);
	int count = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%1d",&a[i][j]);
			b[i][j] = count;
				count++;
		}
	}
	search();
	

	
	return 0;
}