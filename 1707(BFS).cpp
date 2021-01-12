#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int T, V, E;
vector<int> vc[20001];
int visit[20001];
bool bfs(int n)
{
	queue<int> q;
	q.push(n);
	visit[n] = 1;
	while (1)
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < vc[now].size(); i++)
		{
			int next = vc[now][i];

			if (visit[next] == visit[now]) {
				
				return false;
			}
			else if (visit[next] == 0)
			{
				if (visit[now] == 1)
					visit[next] = 2;
				else
					visit[next] = 1;

				q.push(next);

			}

		}

		if (q.empty())
		{
			return true;
		}
	}

}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &V, &E);
		for (int j = 0; j < E; j++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			vc[a].push_back(b);
			vc[b].push_back(a);
		}

		for (int j = 1; j <= V; j++)
		{ 
			if (visit[j] == 0)
			{
				if (bfs(j) == false)
				{
					printf("NO\n");
					break;
				}
			}
			if (j == V)
			{
				printf("YES\n");
			}
		}

		for (int j = 1; j <= V; j++)
		{
			vc[j].clear();
			visit[j] = 0;
		}

	}




	return 0;
}
