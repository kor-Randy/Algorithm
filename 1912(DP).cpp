#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001];
int N;
int ma[100001];

int dp(int n)
{

	if (n == 0)
		return ma[n] = arr[0];
	else if (ma[n] != 0)
		return ma[n];
	else
	{
		
		return ma[n] = max(dp(n - 1) + arr[n], arr[n]);

	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	dp(N - 1);

	sort(&ma[0], &ma[N]);

	printf("%d", ma[N - 1]);

	return 0;
}
