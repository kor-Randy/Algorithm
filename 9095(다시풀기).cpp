#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N,T;
int arr[11];
int dp(int n)
{
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
		
	for (int i = 4; i <= N; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	return arr[n];
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);

		printf("%d\n",dp(N));

	}

	return 0;
}
