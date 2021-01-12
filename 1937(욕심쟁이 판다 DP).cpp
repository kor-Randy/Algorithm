#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[501][501];
int visit[501][501];
int temp, cnt, res;
int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0 };

int dp(int x, int y)
{
	
	if (visit[x][y] != 0)
	{
		return visit[x][y];
	}
	else
	{
		int ma = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny]<=arr[x][y])
				continue;
			else
			{
				ma = max(ma, dp(nx, ny));
			}

			

		}
		visit[x][y] = ma + 1;
		res = max(res, visit[x][y]);

		return visit[x][y];
	}

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
			dp(i, j);
		}
	}

	printf("%d", res);

	return 0;
}
