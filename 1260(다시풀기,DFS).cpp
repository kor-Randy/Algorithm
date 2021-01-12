#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> vc[1001];
int N, M, V;
int visit[1001];

void dfs(int now)
{
	visit[now] = 1;
	printf("%d ", now);
	for (int i = 0; i < vc[now].size(); i++)
	{
		int next = vc[now][i];

		if (visit[next] == 0)
		{
			dfs(next);
		}

	}

}

void bfs(int n)
{
	queue<int> q;
	q.push(n);
	visit[n] = 1;
	while (1)
	{
		int now = q.front();
		q.pop();
		printf("%d ", now);

		for (int i = 0; i < vc[now].size(); i++)
		{
			int next = vc[now][i];

			if (visit[next] == 0)
			{
				visit[next] = 1;
				q.push(next);
			}

		}
		if (q.empty())
			break;

	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}

	for (int i = 0; i < N; i++)
	{
		sort(vc[i].begin(), vc[i].end());
	}

	dfs(V);
	printf("\n");
	for (int i = 1; i <= N; i++)
		visit[i] = 0;
	bfs(V);

	return 0;
}
