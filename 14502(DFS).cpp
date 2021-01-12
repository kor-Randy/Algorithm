
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
int arr[9][9];
int change[9][9];
int change2[9][9];
vector<pair<int, int>> virus;
pair<int,int> one, two, three;
int x[4] = { 0,-1,0,1 };
int y[4] = { -1,0,1,0 };
int wallcnt;
int zerocnt;
int res;

void bfs()
{
	queue<pair<int, int>> q;
	int zero = zerocnt;
	memcpy(change2, change, sizeof(change));
	for(int i=0;i<virus.size();i++)
	{
		q.push(virus[i]);
	}

	while (1)
	{
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			
				if (now.first + x[i] < 0 || now.first + x[i] >= N || now.second + y[i] < 0 || now.second+ y[i] >= M)
					continue;
				else
				{
					if (change2[now.first + x[i]][now.second + y[i]] == 0)
					{
						zero--;
						q.push({ now.first + x[i] ,now.second + y[i] });
						change2[now.first + x[i]][now.second + y[i]] = 2;
					}
				}
			
		}

		if (q.empty())
			break;

	}

	res = max(res, zero);

}

void makewall(int cnt)
{
	if (cnt == 3)
	{
		
		bfs();
		return;

	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			

			if (change[i][j] == 0)
			{
				change[i][j] = 1;
				cnt++;
				makewall(cnt);
				change[i][j] = 0;
				cnt--;
			}

			

		}
	}
}




int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2)
				virus.push_back({ i,j });
			else if (arr[i][j] == 0)
				zerocnt++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			change[i][j] = arr[i][j];
		}
	}

	makewall(0);

	printf("%d\n", res-3);
	return 0;
}
