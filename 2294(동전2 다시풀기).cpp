#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int arr[101];
int visit[10001];


void dp()
{
	visit[0] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = arr[i]; j <= K; j++)
		{
			visit[j] = min(visit[j], visit[j - arr[i]] + 1);
			}
	}

}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(&arr[0], &arr[N]);
	if (arr[0] > K)
	{
		printf("-1");
		return 0;
	}
	for (int i = 1; i <= K; i++)
	{
		visit[i] = 1000000;
	}

	dp();

	if (visit[K] >= 1000000)
		printf("-1");
	else
		printf("%d", visit[K]);

	return 0;
}
