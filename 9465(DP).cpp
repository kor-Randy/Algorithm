#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int N,T;
int arr[2][100001];
int sum[2][100001];

int dp1(int, int);

int dp0(int x, int y)
{
	if (y == 0)
		return sum[x][y] = arr[x][y];
	else if (y == 1)
	{
		return sum[x][y] = arr[1][y - 1] + arr[x][y];
	}
	else if (sum[x][y] != -1)
		return sum[x][y];
	else
	{
		

		return sum[x][y] = max(dp1(1, y - 1), dp1(1, y - 2)) + arr[x][y];
			
	}
}
int dp1(int x, int y)
{
	if (y == 0)
		return sum[x][y] = arr[x][y];
	else if (y == 1)
	{
		return sum[x][y] = arr[0][y - 1] + arr[x][y];
	}
	else if (sum[x][y] != -1)
		return sum[x][y];
	else
	{


		return sum[x][y] = max(dp0(0, y - 1), dp0(0, y - 2)) + arr[x][y];

	}
}

int main()
{
	scanf("%d", &T);
	for(int i=0;i<T;i++)
	{
		scanf("%d", &N);
		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < N; k++)
			{
				scanf("%d", &arr[j][k]);
			}
		}
		
		memset(sum[0], -1, sizeof(int)*N);
		memset(sum[1], -1, sizeof(int)*N);

		printf("%d\n", max(dp0(0, N - 1), dp1(1, N - 1)));


	}

	return 0;
}
