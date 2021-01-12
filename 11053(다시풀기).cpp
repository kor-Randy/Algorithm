#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int visit[1001];

void dp()
{
	visit[0] = 1;
	for (int i = 1; i < N; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[i] > arr[j])
			{
				visit[i] = max(visit[i], visit[j] + 1);
			}
			else
			{
				visit[i] = max(1,visit[i]);
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

	dp();

	sort(&visit[0], &visit[N]);
	printf("%d", visit[N - 1]);

	return 0;
}
