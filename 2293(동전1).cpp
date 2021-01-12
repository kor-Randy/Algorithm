#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int coin[101];
int N,K;
int arr[10001];

int dp()
{

	for (int i = 0; i < N; i++)
	{
		if (coin[i] > K)
			continue;
		//coin[i] = 사용할 코인 가격	
			for (int j = 1; j <= K; j++)
			{
				if (coin[i] > j)
					continue;
				
				arr[j] += arr[j - coin[i]];
				//현재 사용하는 코인가격을 뺀 경우의수를 더한다
				//if coin[i]==5 이고 j=10이면
				//arr[10]+=arr[5]에다가 5짜리 붙힌거
			}
		
	}

	return arr[K];

}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &coin[i]);
	}
	arr[0] = 1;


	printf("%d", dp());



	return 0;
}
