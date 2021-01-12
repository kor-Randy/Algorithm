#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int res, temp, cnt;
int N;
int arr[501][501];
int visit[501][501];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int dfs(int x, int y, int c)
{
	if (visit[x][y] != 0)
		return visit[x][y];

	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i];
		int ny = y + yy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		else
		{
			if (arr[x][y] < arr[nx][ny])
			{
				
					visit[x][y]=max(visit[x][y],dfs(nx, ny, c + 1) + 1);
			}
		}
	}


	return visit[x][y];
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dfs(i, j, 1);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			res = max(res, visit[i][j]);
		}
	}
	printf("%d",res+1);

	return 0;
}
