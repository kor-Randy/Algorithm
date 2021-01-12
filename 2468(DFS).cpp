#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
int arr[101][101];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int res, cnt, temp;
int check[102];
int visit[101][101];
int h;
int dfs(int x,int y)
{

	if (arr[x][y] <= h || visit[x][y]!=0)
		return 0;
	else 
	{
		//들렸던 곳이 아니고 살아남는 곳이다
		visit[x][y] = 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			else if (visit[nx][ny] != 0)
				continue;
			else
			{
				
				dfs(nx, ny);
				//사방에 들어간다

			}

		}

		return 1;

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

	for (int i = 0; i <= 100; i++)
	{
		h = i;
		
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				if(dfs(j, k)==1)
					check[h]++;
			}
		}

	

		memset(visit, 0, sizeof(visit));

	}

	sort(&check[0], &check[101]);

	printf("%d", check[100]);


	return 0;
}
