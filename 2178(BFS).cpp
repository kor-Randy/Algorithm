#include<stdio.h>
#include<iostream>
#include <queue>
#include <vector>
#include<algorithm>
#include<cstring>

using namespace std;

int arr[101][101];
int check[101][101];

int N, M;
void search()
{

	
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][0] = 1;
	while (1)
	{
		
		pair<int, int> now = q.front();
		q.pop();

		if (arr[now.first - 1][now.second] == 1 && check[now.first - 1][now.second] == 0 && now.first>0)
		{
			check[now.first - 1][now.second] = check[now.first][now.second] + 1;
			q.push(make_pair(now.first - 1, now.second));
		}

		if (arr[now.first + 1][now.second] == 1 && check[now.first + 1][now.second] == 0)
		{
			check[now.first + 1][now.second] = check[now.first][now.second] + 1;
			q.push(make_pair(now.first + 1, now.second));
		}
		
		if (arr[now.first][now.second - 1] == 1 && check[now.first][now.second - 1] == 0 && now.second>0)
		{
			check[now.first][now.second - 1] = check[now.first][now.second] + 1;
			q.push(make_pair(now.first, now.second - 1));
		}
		
		if (arr[now.first][now.second + 1] == 1 && check[now.first][now.second + 1] == 0)
		{
			check[now.first][now.second + 1] = check[now.first][now.second] + 1;
			q.push(make_pair(now.first, now.second + 1));
		}

		if (q.empty())
		{
			printf("%d", check[N - 1][M - 1]);
			break;
		}


	}

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	search();

	return 0;
}