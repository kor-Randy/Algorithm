#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int start, des;
int visit[101];
int res;
vector<int> vc[101];


void bfs()
{

	queue<int> q;
	q.push(start);
	visit[start] = 1;
	res = -1;
	while (1)
	{
		int now = q.front();
		q.pop();
		res++;
		if (now == des)
			break;

		for (int i = 0; i < vc[now].size(); i++)
		{
			int next = vc[now][i];

			if (visit[next] == 0)
			{
				
				q.push(next);
				visit[next] = 1;
				

			}

		}
		if (q.empty())
		{
			res = -1;
			break;
		}

	}

}

int dfs(int n)
{
	visit[n] = 1;
	if (n == des)
		return 1;

	
	
		for (int i = 0; i < vc[n].size(); i++)
		{
			int next = vc[n][i];
			//printf("n = %d , next = %d visit[next] = %d\n", n, next,visit[next]);
			if (visit[next] == 0)
			{
				//printf("res++\n");
				res++;
				if (dfs(next) == 1)
				{
					//printf("desµµÂø\n");
					return 1;


				}
				else
				{
					//printf("res--\n");
					res--;
				}
					
			}

		}



		return 2;

}

int main()
{
	scanf("%d", &N);

	scanf("%d %d", &start, &des);

	scanf("%d", &M);

	for (int i = 1; i <= M; i++)
	{
		int a, b ;
		scanf("%d %d", &a, &b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}
	dfs(start);
	if (res == 0)
		printf("-1");
	else
	printf("%d", res);

	return 0;
}
