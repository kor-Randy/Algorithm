#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int arr[1001][1001];

int dp(int n, int k)
{

	if (k == 1)
		return arr[n][k] = n;
	else if (k == 0)
		return arr[n][k] = 1;
	else if (n == k)
		return arr[n][k] = 1;
	else if (arr[n][k] != 0)
		return arr[n][k];
	else
	{

		return arr[n][k] = (dp(n - 1, k) + dp(n - 1, k - 1))%10007;
	}
}

int main()
{
	scanf("%d %d", &N, &K);

	printf("%d", dp(N, K));

	return 0;
}
