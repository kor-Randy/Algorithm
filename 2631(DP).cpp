#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[201];
int res, temp, cnt;
int visit[201];
void dp()
{
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (arr[j] < arr[i])
			{
				visit[i] = max(visit[i], visit[j] + 1);
			}
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
	for (int i = 0; i < N; i++)
	{
		visit[i] = 1;
	}
	dp();
	sort(&visit[0], &visit[N]);

	printf("%d", N - visit[N - 1]);

	return 0;
}
