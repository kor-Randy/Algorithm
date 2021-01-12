#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;


int N, K;
int arr[201][201];

int dp(int k, int n)
{
	if (k == 1)
		return arr[k][n];
	else if (k == 2)
	{
		
			return arr[k][n] = n + 1;
		
	}
	else if (arr[k][n] != 0)
		return arr[k][n];
	else
	{
		
		
			for (int j = 0; j <= n; j++)
			{
				arr[k][n] += dp(k - 1, n - j) % 1000000000;
				arr[k][n] %= 1000000000;
			}

		
			return arr[k][n] % 1000000000;

	}

}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= N; i++)
	{
		arr[1][i] = 1;
	}

	printf("%d", (dp(K, N) % 1000000000));

	return 0;
}
