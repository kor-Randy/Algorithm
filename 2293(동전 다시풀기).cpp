#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int arr[101];
int res, cnt, temp;
int visit[10001];
void dp()
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > K)
			continue;
		for (int j = 1; j <= K; j++)
		{
			if (arr[i] > j)
				continue;
			else
			{
				visit[j] += visit[j - arr[i]];
			}
		}
	}

}

int main()
{
	scanf("%d %d", &N,&K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		visit[0] = 1;
	}
	dp();

	printf("%d", visit[K]);

	return 0;
}
