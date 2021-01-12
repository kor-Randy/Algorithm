#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int coin[21];
int N,M,TK;
int arr[10001];
int dp(int n)
{
	if (arr[n] == coin[0])
		return arr[n] = 1;
	else if (arr[n] != 0)
	{
		return arr[n];
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			arr[n] += dp(n - coin[i]);
		}
		return arr[n];
	}

}

int main()
{
	scanf("%d", &TK);

	for (int i = 0; i < TK; i++)
	{
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &coin[j]);
		}
		scanf("%d", &M);


		printf("%d\n",dp(M));
		memset(arr, 0, sizeof(arr));
	}

	return 0;
}
