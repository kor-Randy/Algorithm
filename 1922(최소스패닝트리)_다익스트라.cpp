#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M;
vector<pair<int, int>> vc[1001];
int res, temp, cnt;
int visit[1001];

void dijk()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,1 });
	while (1)
	{
	
		int now = pq.top().second;
		int d = -pq.top().first;
		pq.pop();
		if (visit[now] == 1)
			continue;
		visit[now] = 1;
		res += d;
		N--;
		//printf("now : %d , d : %d\n", now, d);

		for (int i = 0; i < vc[now].size(); i++)
		{
			int next = vc[now][i].first;
			int nd = vc[now][i].second;

			if (visit[next] == 1)
				continue;
			else
			{
				pq.push({ -nd,next });
				

			}

		}

		if (pq.empty()|| N==0)
			break;
	
	}

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vc[a].push_back({ b,c });
		vc[b].push_back({ a,c });
	}

	dijk();
	printf("%d", res);

	return 0;
}
