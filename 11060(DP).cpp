#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int visit[1001];
int res, temp, cnt;

void dp()
{
	visit[0] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= arr[i]; j++)
		{
			if (i + j >= N)
				break;
			visit[i+j] = min(visit[i+j], visit[i] + 1);
		}
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		visit[i] = 10000;
		scanf("%d", &arr[i]);
	}
	dp();
	if (visit[N - 1] >= 10000)
		printf("-1");
	else
		printf("%d", visit[N - 1]);

	return 0;
}
