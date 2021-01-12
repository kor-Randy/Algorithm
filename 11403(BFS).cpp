#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

int N;
int arr[101][101];
int check[101][101];

void bfs()
{
	string s;
	s.
	queue<int> q;
	

	for (int i = 0; i < N; i++)
	{
		q.push(i);

		while (1)
		{
			int now = q.front();
			q.pop();

			for (int j = 0; j < N; j++)
			{
				if (arr[now][j] == 1 && check[i][j]!=1)
				{
					check[i][j] = 1;
					q.push(j);
				}
			}
			if (q.empty())
				break;
			
		}

	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", check[i][j]);
		}
		printf("\n");
	}

	return 0;
}