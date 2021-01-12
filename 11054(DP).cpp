#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int d[1001];
int u[1001];
int b[1001];
int temp, res, cnt;

void down(int n)
{
	d[n] = 1;
	for (int i = N-1; i > n; i--)
	{
		if (arr[i] < arr[n])
		{
			d[n] = max(d[n], d[i] + 1);
		}
	}

}

void up(int n)
{
	u[n] = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < arr[n])
		{
			u[n] = max(u[n], u[i] + 1);
		}
	}
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = N-1; i >= 0; i--)
		down(i);

	for (int i = 0; i < N; i++)
		up(i);

	for (int i = 0; i < N; i++)
		b[i] = d[i] + u[i] - 1;

	sort(&b[0], &b[N]);

	printf("%d", b[N - 1]);

	


	return 0;
}
