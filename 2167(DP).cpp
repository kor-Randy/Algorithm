#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[301][301];
int sum[301][301];
int N, M,K;
int ii, jj, x, y;




int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	scanf("%d", &K);

	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &ii, &jj, &x, &y);
	
		int temp = 0;

		for (int j = ii; j <= x; j++)
		{
			for (int k = jj; k <= y; k++)
			{
				temp += arr[j][k];
			}
		}
		printf("%d\n", temp);

	}

	return 0;
}
