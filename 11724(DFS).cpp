#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int check[1001];
int visit[1001];
int arr[1001][1001];
void dfs(int now)
{
	if (visit[now] == 0)
	{
		visit[now] = 1;
		for (int j = 1; j <= N; j++)
		{

			if (arr[now][j] == 1)
			{
				
				check[j] = check[now];

				dfs(j);
			}
		}
	}

}

int main()
{
	int count = 1;
	scanf("%d %d", &N, &M);

	

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[b][a] = arr[a][b] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		check[i] = i;
	}



	for (int i = 1; i <= N; i++)
	{
	
		dfs(i);
	}
	

	sort(&check[0], &check[N+1]);

	for (int i = 1; i < N; i++)
	{
		if (check[i] != check[i + 1])
			count++;
	}

	printf("%d", count);

	return 0;
}