#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[301];
int res, temp, cnt;
int visit[301][3];

int dp(int n, int m)
{
	
	if (n == 1)
	{
		if (m == 1)
			return visit[n][m] = arr[n];
		else
			return visit[n][m] = 0;
	}
	else if (n == 2)
	{
		if (m == 1)
		{
			return visit[n][m] = arr[1] + arr[2];
		}
		else
		{
			return visit[n][m] = arr[2];
		}
	}
	else if (visit[n][m] != 0)
		return visit[n][m];
	else
	{
		if (m == 1)
		{
			return visit[n][m] = dp(n - 1, 2) + arr[n];
		
		}
		else
		{
			return visit[n][m] = max(dp(n - 2, 1), dp(n - 2, 2)) + arr[n];
		}

	}

}


int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", max(dp(N, 1), dp(N, 2)));

	
	return 0;
}
