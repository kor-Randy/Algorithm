#include<stdio.h>
#include<iostream>
using namespace std;

int N;
int arr[1001];
int dp(int n)
{
	if (n == 1)
		return arr[n] = 1;
	else if (n == 2)
		return arr[n] = 2;
	else if (arr[n] != 0)
		return arr[n]%10007;
	else
	{
		return arr[n] = dp(n - 1) % 10007 + dp(n - 2) % 10007;
	}
}

int main()
{
	scanf("%d", &N);

	printf("%d", dp(N)%10007);

	return 0;
}