
#include<stdio.h>
#include<iostream>
using namespace std;

int N;
unsigned long long arr[101][101];
unsigned long long check[101][101];
int xx[2] = { 0,1 };
int yy[2] = { 1,0 };
unsigned long long temp, cnt, res;

unsigned long long dp(int x, int y)
{
	
	

	if (check[x][y] != 0)
	{
		return check[x][y];
	}
	else
	{
		
		int length = arr[x][y];
		if (length == 0)
			return check[x][y];
		for (int i = 0; i < 2; i++)
		{
			int nx = x + xx[i] * length;
			int ny = y + yy[i] * length;
			if (nx >= N || ny >= N)
				continue;
			else if (nx == N - 1 && ny == N - 1)
			{
				//printf("%d %d에서 도착\n", x, y);
				check[x][y]++;
			}
			else
			{
				check[x][y] += dp(nx, ny);
				//printf("x : %d , y : %d에서 nx : %d , ny : %d , check[x][y] = %d\n",x,y, nx, ny,check[x][y]);
			}
		}

		return check[x][y];

	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}


	printf("%llu", dp(0, 0));

	


	return 0;
}
