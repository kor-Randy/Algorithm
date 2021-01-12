#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int T, N;
int arr[11];
int dp(int n)
{
	if (arr[n] != 0)
		return arr[n];
	else
	{
		return arr[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);
	}
}

int main()
{
	scanf("%d", &T);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);

		printf("%d\n", dp(N));

	}

	return 0;
}
