#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int arr[101][101];
int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = 1000000000;
		}
	}
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		
		arr[a][b] = min(arr[a][b],c);
	}
	

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			
			for (int k = 1; k <= N; k++)
			{
				
				arr[j][k]=min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
	
	for (int i = 1; i <= N; i++)
	{
		
			arr[i][i] = 0;
		
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (arr[i][j] >= 100000000)
				printf("0 ");
			else
				printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
