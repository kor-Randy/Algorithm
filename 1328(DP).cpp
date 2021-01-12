#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, L, R;
int arr[101][101][101];
int res, cnt, temp;

int dp(int n, int l, int r)
{
	if (l + r > n + 1 || l == 0 || r == 0)
		return 0;
	else if (n == 1)
	{
		return arr[n][l][r] = 1;
	}
	else if (arr[n][l][r] != 0)
		return arr[n][l][r];
	else
	{
		arr[n][l][r] = dp(n - 1, l - 1, r) + dp(n - 1, l, r - 1) + dp(n - 1, l, r)*(N-2);
		return arr[n][l][r] % 1000000007;
	}

}

int main()
{
	scanf("%d %d %d", &N, &L, &R);
	printf("%d",dp(N, L, R));
	return 0;
}
