#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int T, N;
int arr[101];//Â¦¼ö¸é ´ÝÈ÷°í È¦¼ö¸é ¿­¸°°Í
int res;
int dp(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j%i == 0)
			{
				arr[j]++;
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		if (arr[i] % 2 == 1)
		{
			res++;
		}
		
	}
	return res;

}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);

		printf("%d\n", dp(N));
		memset(arr, 0, sizeof(arr));
		res = 0;

	}

	return 0;
}
