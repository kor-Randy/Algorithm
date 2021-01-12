#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[101];
unsigned long long visit[101][30];
long long res, cnt, temp;

unsigned long long dp(int index, int num)
{
	//printf("i : %d , num : %d\n", index, num);

	if (index == 1 )
	{
		if (num == arr[1])
			return visit[index][num] = 1;
		else
			return 0;
	}
	else if (visit[index][num] != 0)
		return visit[index][num];
	else
	{
		if (num - arr[index] >= 0)
		{
			visit[index][num] += dp(index - 1, num - arr[index]);
		}
		
		if (num + arr[index] <= 20)
		{
			visit[index][num] += dp(index - 1, num + arr[index]);
		}

		return visit[index][num];
	}
}

int main()
{
	
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	

	printf("%llu", dp(N - 1, arr[N]));

	return 0;
}