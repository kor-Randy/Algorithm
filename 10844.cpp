#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define M 1000000000
int arr[101][10];
int N;
int res;
int dp(int n,int last)
{
	if (n == 1)
	{
		if (last == 0)
			return arr[n][last] = 0;
		else
			return arr[n][last] = 1;
	}
	else if (arr[n][last] != 0)
		return arr[n][last];
	else
	{
		
		if (last == 0)
			return arr[n][last] = dp(n - 1, last + 1) % M;
		else if (last == 9)
			return arr[n][last] = dp(n - 1, last - 1) % M;
		else
		{
			return arr[n][last] = dp(n - 1, last - 1) % M + dp(n - 1, last + 1) % M;
		}


	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < 10; i++)
	{
		res += dp(N, i)%M;
		//printf("res : %d\n", res);
		res = res%M;
	}

	printf("%d", res);
	

	return 0;
}
