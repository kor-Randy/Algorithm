#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int> vc[20001];
int N, M;
int res, temp, cnt;
int arr[20001];

void bfs()
{
	queue<int> q;
	q.push(1);
	arr[1] = 0;

	while (1)
	{
		int now = q.front();
		q.pop();
		//printf("now : %d ,arr[now] = %d\n", now, arr[now]);
		for (int i = 0; i < vc[now].size(); i++)
		{
			int next = vc[now][i];
			if (arr[next] != 0 || next==1)
			{
				//이미 값이 존재하다면
				continue;
			}
			else
			{
				arr[next] = arr[now] + 1;
				q.push(next);
			}
		}

		if (q.empty())
			break;
		

	}


}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}

	bfs();
	int mi = 0;
	for (int i = 2; i <= N; i++)
	{
		mi = max(mi, arr[i]);
	}

	int a=0, b=0, c=0;

	b = mi;

	for (int i = 2; i <= N; i++)
	{
		if (arr[i] == mi && a==0)
		{
			a = i;
			c++;
		}
		else if (arr[i] == mi)
		{
			c++;
		}

	}
	printf("%d %d %d", a, b, c);


	return 0;
}
