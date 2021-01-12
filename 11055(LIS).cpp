#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int arr[1001];
int visit[1001];

void lis()
{


	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				visit[i] = max(visit[i], visit[j] + arr[i]);
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
		visit[i] = arr[i];
	}

	lis();
	int res = 0;
	
	sort(&visit[0], &visit[N]);

	printf("%d", visit[N-1]);

	return 0;
}
