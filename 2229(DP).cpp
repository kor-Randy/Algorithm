#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int d[1001][1001];

int ma(int l, int r)
{
	int m=0;
	for (int i = l; i <= r; i++)
		m = max(m, arr[i]);

	return m;
}
int mi(int l, int r)
{
	int m = 100000;
	for (int i = l; i <= r; i++)
		m = min(m, arr[i]);

	return m;
}

int dp(int l, int r)
{
	if (l == r)
		return d[l][r] = 0;
	else if (r - l == 1)
	{
		int b = ma(l, r);
		int s = mi(l, r);
		return d[l][r] = b - s;
	}
	else if (d[l][r] != -1)
		return d[l][r];
	else
	{
		int b = ma(l,r);
		int s = mi(l, r);
		d[l][r] = b - s;
		for (int i = l; i < r; i++)
		{
			d[l][r] = max(d[l][r], dp(l, i) + dp(i + 1, r));
		
		}

		return d[l][r];

	}


}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			d[i][j] = -1;
		}
	}


	dp(0, N - 1);

	printf("%d", d[0][N-1]);

	return 0;
}
