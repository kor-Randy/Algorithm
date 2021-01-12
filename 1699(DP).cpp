#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int a, b;
int res, cnt, temp;
int arr[100001];


int dfs(int n)
{
	if (sqrt(n) == (int)sqrt(n))
		return arr[n] = 1;
	else if (arr[n] != 1000000)
		return arr[n];
	else
	{
		
		a = sqrt(n);
		for (int i = a; i > 0; i--)
		{
			arr[n] = min(arr[n], dfs(n - pow(i, 2)) + 1);
		}
		return arr[n];

	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i <= N; i++)
	{
		arr[i] = 1000000;
	}

	dfs(N);
	printf("%d", arr[N]);

	return 0;
}
