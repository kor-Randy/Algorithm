#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, M;
vector<pair<int, int>> vc[1001];
int start, des;
int d[1001];

void dijk()
{

	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });
	d[start] = 0;

	while (1)
	{
	
		int cost = -pq.top().first;//¾ç¼ö
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < vc[now].size(); i++)
		{
			pair<int, int> temp = vc[now][i];
			if (cost+temp.second < d[temp.first])
			{
				d[temp.first] = cost + temp.second;
				pq.push({ -d[temp.first],temp.first });
			}
			else
			{
				continue;
			}
		}
		if (pq.empty())
			break;

	
	}

}

int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 1;i <= M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vc[a].push_back({ b,c });
	}
	scanf("%d %d", &start, &des);
	for (int i = 1; i <= N; i++)
	{
		d[i]=100000001;
	}

	dijk();

	printf("%d", d[des]);

	return 0;
}
