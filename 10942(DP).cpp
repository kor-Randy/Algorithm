#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[2001];
int visit[2001][2001];
void dp()
{

	for (int i = 1; i <= N; i++)
	{
		//까지
		for (int j = 1; j <= i; j++)
		{
			//부터
			if (i == j)
			{
				visit[i][j] = 1;
			}
			else if (i - j == 1)
			{
				if (arr[i] == arr[j])
					visit[j][i] = 1;
			}
			else
			{
				if (arr[i] == arr[j])
				{
					if (visit[j + 1][i - 1] == 1)
						visit[j][i] = 1;
				}
			}

		}
	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	dp();
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", visit[a][b]);

	}

	return 0;
}
