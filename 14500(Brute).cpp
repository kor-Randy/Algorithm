#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[501][501];
int res, temp, cnt;
int xx[4] = { 0,0,1,-1 };
int yy[4] = { -1,1,0,0 };
int visit[501][501];

void dfs(int, int, int, int);
void fuck(int, int);

void brute()
{

	for (int i = 0; i < N; i++)
	{
		for(int j=0;j<M;j++)
		{
			//printf("x : %d , y : %d\n", i, j);
			visit[i][j] = 1;
			dfs(i, j, arr[i][j], 0);
			visit[i][j] = 0;

			fuck(i,j);

		}
	}
	
}

void fuck(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			if (x + 1 >= N || y + 2 >= M)
				continue;
			else
			{
				res = max(res, arr[x][y] + arr[x + 1][y + 1] + arr[x][y + 1] + arr[x][y + 2]);
			}
		}
		else if (i == 1)
		{
			if (x + 2 >= N || y - 1 <0)
				continue;
			else
			{
				res = max(res, arr[x][y] + arr[x + 1][y] + arr[x+1][y - 1] + arr[x+2 ][y]);
			}
		}
		else if (i == 2)
		{
			if (x - 1 <0 || y + 2 >= M)
				continue;
			else
			{
				res = max(res, arr[x][y] + arr[x][y + 1] + arr[x-1][y + 1] + arr[x][y + 2]);
			}
		}
		else
		{
			if (x + 2 >= N || y + 1 >= M)
				continue;
			else
			{
				res = max(res, arr[x][y] + arr[x + 1][y + 1] + arr[x+1][y] + arr[x+2][y]);
			}
		}
	}
}

void dfs(int x, int y,int sum,int c)
{

	if (c == 3)
	{
		res = max(res, sum);
		//printf("%d\n", res);
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny]==1)
				continue;
			else
			{
				visit[nx][ny] = 1;
				//printf("sum : %d , value : %d\n", sum,arr[nx][ny]);
				dfs(nx, ny, sum+arr[nx][ny], c + 1);
				visit[nx][ny] = 0;
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
		}
	}

	brute();

	printf("%d", res);

	return 0;
}
