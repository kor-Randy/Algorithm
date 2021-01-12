#include<stdio.h>
#include<iostream>
using namespace std;

int N;
int TK;
unsigned long long arr[68];
unsigned long long  dp(int n)
{
	if (n == 1 || n == 0)
		return arr[n] = 1;
	else if (n == 2)
		return arr[n] = 2;
	else if (n == 3)
		return arr[n] = 4;
	else if (arr[n] != 0)
		return arr[n];
	else
	{
		return arr[n] = dp(n - 1) + dp(n - 2) + dp(n - 3) + dp(n - 4);
	}


}

int main()
{
	scanf("%d", &TK);

	for (int i = 0; i < TK; i++)
	{
		scanf("%d", &N);

		printf("%llu\n", dp(N));
	}

	return 0;
}
