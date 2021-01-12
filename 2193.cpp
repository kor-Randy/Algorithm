#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N;
unsigned long long arr[91][2];

unsigned long long dp(int n, int num)
{
	if (n == 1)
	{
		if (num == 0)
			return arr[n][0] = 0;
		else
			return arr[n][1] = 1;
	}
	else if (arr[n][num] != 0)
		return arr[n][num];
	else
	{
	
		if (num == 0)
		{
			return arr[n][num] = dp(n - 1, 0) + dp(n - 1, 1);
		}
		else
		{
			return arr[n][num] = dp(n - 1, 0);
		}

	}
}

int main()
{
	scanf("%d", &N);

	unsigned long long res = dp(N, 0) + dp(N, 1);

	printf("%llu", res);

	return 0;
}
