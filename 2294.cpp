#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int res, cnt, temp;
int arr[101];
int d[100001];
int visit[101];
int dp(int n)
{
	if (n == 0)
		return 0;
	else
		return d[n];


}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= K; i++)
		d[i] = 1000000;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		d[arr[i]] = 1;
	}

	
	d[0] = 0;

	sort(&arr[0], &arr[N]);

	for (int i = 0; i < N; i++)
		for (int j = arr[i]; j <= K; j++)
			d[j] = min(d[j], d[j - arr[i]] + 1);
	

	
	if (d[K] >= 100000)
		printf("-1");
	else 
		printf("%d", d[K]);


	return 0;
}
