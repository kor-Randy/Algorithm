#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int arr[501][2];
int visit[501][501];

int dp(int l, int r)
{
	if (l == r)
		return 0;
	else if (r - l == 1)
	{
		return visit[l][r] = arr[l][0] * arr[l][1] * arr[r][1];
	}
	else if(visit[l][r]!=pow(2,31)-1)
	{
		return visit[l][r];
	}
	else
	{
		for (int i = l; i < r; i++)
		{
			visit[l][r] = min(visit[l][r], (dp(l, i) + dp(i+1, r) + arr[l][0] * arr[i][1] * arr[r][1]));

		}
	}

	return visit[l][r];


}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = pow(2, 31)-1;
		}
	}

	printf("%d",dp(0, N - 1));

	return 0;
}
