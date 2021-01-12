#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int n, m;
vector<pair<int, int>> vc[201];
int arr[201][201];
int cnt, temp;
int check[201][201];
int past[201];
int res[201][201];
void tracking(int start);

void dijk(int start)
{
	
	priority_queue<pair<int, int>> pq;
	pq.push({ 0,start });

	while (1)
	{
		int now = pq.top().second;
		int score = -pq.top().first;
		pq.pop();

		
		

		for (int i = 0; i < vc[now].size(); i++)
		{
			int next = vc[now][i].first;
			int value = vc[now][i].second;

			if (check[start][next] > check[start][now] + value)
			{
				//이미 구한 값보다 start->...->now->next 가 더 싸다면
				check[start][next] = check[start][now] + value;
				past[next] = now;
				pq.push({ -vc[now][i].second,vc[now][i].first });

			}
			else
			{
				//printf("%d // %d \n", check[start][next] , check[start][now] + value);
			}
			
		}

		if (pq.empty())
		{
			tracking(start);
			

			
			
				break;
		}

		

	}

}

void tracking(int start )
{
	int temp=0;
	for (int i = 1; i <=n; i++)
	{
		if (i == start)
			continue;
		temp = past[i];
		
		if (temp == start)
		{
			//nothing
		}
		else
		{
			while (past[temp]!=start)
			{
				temp = past[temp];
				
				
			}
		}
		//printf("start = %d i= %d past = %d\n", start,i,temp);
		if (temp == start)
			res[start][i] = i;
		else
			res[start][i] = temp;
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		vc[a].push_back({ b , c });
		vc[b].push_back({ a , c });
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if(i!=j)
				check[i][j] = 2000001;
		}
	}

	for (int i = 1; i <= n; i++)
	{
	
		dijk(i);

		
		memset(past, 0, sizeof(past));
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				printf("- ");
			else
				printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
