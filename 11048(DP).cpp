#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int N, M;
int arr[1001][1001];
int sum[1001][1001];
int xx[3] = { 0,-1,-1 };
int yy[3] = { -1,-1,0 };
int res;

int dp(int x, int y)
{
	//printf("%d %d\n", x, y);
	if (x == 1 && y == 1)
	{
		//printf("11");
		return sum[x][y] = arr[x][y];
	}
	else if (sum[x][y] != -1)
	{
		//printf("%d %d\n", x, y);
		//printf("asd");
		return sum[x][y];
	}
	else
	{
		int temp = 0;
		//printf("%d", sum[x][y]);
		

		for (int i = 0; i < 3; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			if (nx < 1 || ny < 1)
				continue;
			temp = max(temp, dp(nx, ny));
		}
		sum[x][y] = temp + arr[x][y];
		res = max(res, sum[x][y]);
		
		return sum[x][y];
	}

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &arr[i][j]);
			sum[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		memset(sum, -1, sizeof(sum));
	}

	int temp = dp(N, M);
	res = max(temp, res);

	printf("%d",res);
	

	

	return 0;
}
