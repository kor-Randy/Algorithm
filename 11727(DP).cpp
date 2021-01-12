#include<stdio.h>
#include<iostream>
using namespace std;

int N;
int arr[1001];

int dp(int n)
{
	if (n == 1)
		return arr[1] = 1;
	else if (n == 2)
		return arr[2] = 3;
	else if (arr[n] != 0)
		return arr[n];
	else
	{
		return arr[n] = (dp(n-1) + 2 * dp(n-2))%10007;
	}
}

int main()
{
	scanf("%d", &N);

	printf("%d",dp(N));

	return 0;
}
