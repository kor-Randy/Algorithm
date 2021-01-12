#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int p[1001];

int  dp(int n)
{
	if (n == 1)
	{
		arr[1] = p[1];
	}
	else if (arr[n] != 0)
		return arr[n];
	else
	{
		for (int i = 1; i <= n; i++)
		{
			arr[n] = max(arr[n], (dp(n-i) + p[i]));
			
		}
	}
	return arr[n];
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &p[i]);
	}
	printf("%d", dp(N));
	return 0;
}
