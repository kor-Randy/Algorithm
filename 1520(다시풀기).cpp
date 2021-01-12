#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[501][501];
int res, cnt, temp;
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int visit[501][501];
int dfs(int x, int y)
{
	int h = arr[x][y];
	if (x == N - 1 && y == M - 1)
		return 1;
	else if (visit[x][y] != -1)
		return visit[x][y];
	else
	{
		visit[x][y] = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			int nh = arr[nx][ny];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || nh >= h)
				continue;
			else
			{
				
				visit[x][y] += dfs(nx, ny);

			}

		}
		

	}
	return visit[x][y];

}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
	scanf("%d", &arr[i][j]);
	visit[i][j] = -1;
	}

	printf("%d", dfs(0, 0));

	return 0;
}
