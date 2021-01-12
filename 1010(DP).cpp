#include<stdio.h>
#include<iostream>

using namespace std;

int N, M,T;
long long res, temp,cnt;
int check[31][31];

int dp(int n, int r)
{

	if (r == 1)
		return check[n][r] = n;
	else if (n == r)
		return check[n][r] = 1;
	else if (check[n][r] != 0)
		return check[n][r];
	else
	{
		return check[n][r] = dp(n - 1, r - 1) + dp(n - 1, r);
	}


}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{

		scanf("%d %d", &N, &M);

	
		printf("%d\n", dp(M, N));
		res = 0;

	}


	return 0;
}