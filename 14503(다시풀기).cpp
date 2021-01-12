#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int fx, fy, fd;
int arr[51][51];
int temp, res, cnt;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

void one(int x, int y)
{
	
	arr[x][y] = 2;
	res++;

}

void two(int x, int y, int d)
{
	if (arr[x][y] == 0)
		one(x, y);
	else if (x < 0 || x >= N || y < 0 || y >= M)
		return;
	
		temp = 0;
		for (int i = 0; i < 4; i++)
		{
			int zx = x + xx[i];
			int zy = y + yy[i];

			if (arr[zx][zy] != 0)
				temp++;
		}

		if (temp == 4)
		{
			if (arr[x + xx[(d + 2) % 4]][y + yy[(d + 2) % 4]] == 1)
			{
				//뒤가 벽
				return;
			}
			else
			{
				//뒤가 벽이 아님
				two(x + xx[(d + 2) % 4], y + yy[(d + 2) % 4], d);
			}
		}
		else
		{
			int nd = 0;
			if (d == 0)
				nd = 3;
			else
				nd = d - 1;
			int nx = x + xx[nd];
			int ny = y + yy[nd];

			if (arr[nx][ny] == 0)
			{
				two(nx, ny, nd);
			}
			else
			{
				two(x, y, nd);
			}
		}


		

		
	

}

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &fx, &fy, &fd);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	two(fx, fy, fd);
	printf("%d",res);


	return 0;
}
