#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int res, temp, cnt;
int arr[41];
int visit[41];

void dp()
{
	visit[0] = 1;
	visit[1] = 2;
	visit[2] = 3;
	for (int i = 3; i < N; i++)
	{
		visit[i] = visit[i - 1] + visit[i - 2];
	}

}

int main()
{
	res = 1;
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < M; i++)
	{
		int a;
		scanf("%d", &a);
		arr[a - 1] = 1;
	}
	dp();
	temp = 1;
	int j = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == 1)
		{
			res *= temp;
			temp = 1;
			j = 0;
		}
		else if (i == N - 1)
		{
			temp = visit[j];
			res *= temp;
		}
		else
		{
			temp = visit[j++];

		}
		

	}
	printf("%d", res);

	return 0;
}
