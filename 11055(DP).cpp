#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int d[1001];
int dp(int n)
{
	//printf("n : %d\n", n);
	if (n == 1)
		return d[n] = arr[n];
	else if (d[n] != arr[n])
		return d[n];
	for (int i = n - 1; i > 0; i--)
	{
		if (arr[n] > arr[i])
		{
			d[n] = max(d[n], dp(i) + arr[n]);
			//printf("d[n] : %d ·Î º¯°æ\n", d[n]);
		}
	}
	return d[n];
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		d[i] = arr[i];
	}
	for(int i=1;i<=N;i++)
		dp(i);
	sort(&d[1], &d[N + 1]);

	printf("%d", d[N]);

	return 0;
}
