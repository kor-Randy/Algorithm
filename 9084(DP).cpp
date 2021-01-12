#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int T, N, M;
int coin[21];
int arr[10001];

void dp()
{
	arr[0] = 1;
	for (int i = 0; i < N; i++)
	{
		//i번째 동전을 사용
		for (int j = coin[i];j <= M; j++)
		{
			arr[j] += arr[j - coin[i]];
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
			scanf("%d", &coin[j]);
		}
		scanf("%d", &M);
		dp();
		printf("%d\n", arr[M]);

		memset(arr, 0, sizeof(arr));
		memset(coin,0,sizeof(coin));

	}
	return 0;
}
