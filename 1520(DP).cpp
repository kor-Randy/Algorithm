#include<stdio.h>
#include<iostream>
using namespace std;

int N, M;
int arr[501][501];
int num[501][501];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int dfs(int x, int y)
{

	//printf("%d %d %d \n", x, y,arr[x][y]);

	if (x == M - 1 && y == N - 1)
	{
		return 1;
	}
	else if (num[x][y] != -1)
	{
		return num[x][y];
	}

	num[x][y] = 0;
	int h = arr[x][y];
	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i];
		int ny = y + yy[i];
		int nh = arr[nx][ny];

		if (nx < 0 || nx >= M || ny < 0 || ny >= N || nh >= h)
			continue;
		else
		{
				num[x][y] += dfs(nx, ny);
				//printf("%d %d %d num = %d\n", x, y, arr[x][y],num[x][y]);
		}

	}

	return num[x][y];

	

}

int main()
{
	scanf("%d %d", &M, &N);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			num[i][j] = -1;
		}
	}

	printf("%d",dfs(0, 0));


	return 0;
}
