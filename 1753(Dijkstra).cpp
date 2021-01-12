#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int V, E;
vector<pair<int,int>> vc[20001];
int res[20001];
int visit[20001];
int start;
int v;

void dijk()
{
	priority_queue<pair<int, int>> q;
	q.push({0, start});
	res[start] = 0;

	while (1)
	{
		int cost = -q.top().first;
		int now = q.top().second;
		q.pop();

		
		for (int i = 0; i < vc[now].size(); i++)
		{
			pair<int, int> temp = vc[now][i];
			if (cost+temp.second < res[temp.first])
			{
				res[temp.first] = cost + temp.second;
				q.push({ -res[temp.first],temp.first });
				//printf("now = %d  ,  temp.fisrt = %d  , res[temp.first] = %d  ,  cost-temp.second = %d\n", now,temp.first ,res[temp.first, cost - temp.second]);
			}
			else
			{
				continue;
			}
			
		}

		if (q.empty())
			break;
		
	}


}

int main()
{
	scanf("%d %d", &V, &E);
	scanf("%d", &start);

	for (int i = 1; i <= E; i++)
	{
		int temp1, temp2, temp3;
		scanf("%d %d %d", &temp1, &temp2, &temp3);
		vc[temp1].push_back({temp2,temp3});
	}
	for (int i = 0; i <= V; i++)
	{
		res[i] = 2000001;
	}

	dijk();


	for (int i = 1; i <= V; i++)
	{
		if (res[i] ==2000001)
			printf("INF\n");
		else
			printf("%d\n", res[i]);

	}
	
	return 0;
}
