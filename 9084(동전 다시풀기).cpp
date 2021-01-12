#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int T, N, M;
int arr[21];
int visit[10001];
int res, cnt, temp;

void dp()
{
	
	visit[0] = 1;

	for (int i = 0; i < N; i++)
	{
		if (arr[i] > M)
			break;
		for (int j = 1; j <= M; j++)
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
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[j]);
		}
		scanf("%d", &M);

		dp();
		
		printf("%d\n", visit[M]);

		for (int j = 1; j <= M; j++)
		{
			visit[j] = 0;
		}

	}

	return 0;
}
