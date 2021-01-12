#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int arr[10001];
int res[10001][3];
int dp(int n,int m)
{
	if (n == 1)
	{
		return res[n][1] = arr[n];
	}
	else if (n == 2)
	{
		if(m==1)
			return res[n][1] = arr[1] + arr[2];
		else
			return res[n][2] = arr[n];
	}
	else if (res[n][m] != 0)
	{
		return res[n][m];
	}
	else
	{
		if (m == 1)
			return res[n][m] = max(dp(n - 1, 2) + arr[n], dp(n - 1, 1));
		else
			return res[n][m] = max(dp(n - 2, 1), dp(n - 2, 2)) + arr[n];
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i < N+1; i++)
	{
		scanf("%d", &arr[i]);
	}

	dp(N, 1);
	dp(N, 2);

	printf("%d", max(res[N][1], res[N][2]));

	return 0;
}