#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int v[101];
int N, K;
int arr[10001];
int res;
int dp()
{
	
	for (int j = 0; j < N; j++)
	{
		if (v[j] > K)
			continue;
		for (int i = 1; i <= K; i++)
		{
			if (v[j] > i)
			{
				
				continue;

			}
			else
			{
				
			arr[i] += arr[i - v[j]];
			}
		}

	}
		
	return res = arr[K];
}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &v[i]);
	}
	
	memset(arr, 0, sizeof(arr));
	arr[0] = 1;
	printf("%d", dp());

	return 0;
}
