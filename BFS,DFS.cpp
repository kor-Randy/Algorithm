#include<stdio.h>
#include<iostream>
#include <queue>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;


int N, M, start;

queue<int> q;

vector<int> v[1001];
int checked[1001];

int checked2[1001];

void dfs(int now)
{

	checked[now] = 1;
	printf("%d ", now);
	for (int i = 0; i < v[now].size(); i++)
	{
		if (checked[v[now][i]] != 1)
		{
			dfs(v[now][i]);
		}
		else
		{
			//ÀÌ¹Ì °¬´ø °÷
		}
	}

	

}

void bfs(int start)
{
	printf("%d ", start);
	checked2[start] = 1;
	q.push(start);
	while(1)
	{
		int now = q.front();
		q.pop();

		


		for (int i = 0; i < v[now].size(); i++)
		{
			if(checked2[v[now][i]]!=1)
			{
				printf("%d ", v[now][i]);
				checked2[v[now][i]] = 1;
				q.push(v[now][i]);
			}
		}
		if (q.empty())
		{
			break;
		}
	}


}

bool compare(int a, int b)
{

	return a < b;
}

int main()
{
	scanf("%d %d %d", &N, &M, &start);

	for (int i = 0; i < M ; i++)
	{
		int temp1, temp2;
		scanf("%d %d", &temp1, &temp2);
		v[temp1].push_back(temp2);
		v[temp2].push_back(temp1);
		sort(v[temp1].begin(), v[temp1].end(),compare);

		sort(v[temp2].begin(), v[temp2].end(),compare);
	}

	

	dfs(start);
	printf("\n");
	bfs(start);


	
	return 0;
}