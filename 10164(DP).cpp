#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M, K;
int arr[16][16];
int visit[16][16];
int res, cnt, temp;
pair<int,int> start, des;
int xx[2] = { 1,0 };
int yy[2] = { 0,1 };
int dfs(int x,int y)
{
	if (x == des.first && y == des.second)
	{
		return 1;
	}
	else if (visit[x][y]!=0)
	{
		return visit[x][y];
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];

			if (nx > des.first || ny > des.second)
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
	scanf("%d %d %d", &N, &M, &K);
	res = 1;
	if (K != 0)
	{
		int a, b;
		a = (K-1) / M;
		b = (K - 1) % M;

		start = { 0,0 };
		des = { a,b };
		dfs(0,0);
		res *= visit[start.first][start.second];
		start = { a,b };
		des = { N-1,M-1 };
		dfs(a,b);
		res *= visit[start.first][start.second];

	}
	else
	{
		start = { 0,0 };
		des = { N - 1,M - 1 };
		dfs(0,0);
		res *= visit[start.first][start.second];
	}
	printf("%d", res);

	return 0;
}
