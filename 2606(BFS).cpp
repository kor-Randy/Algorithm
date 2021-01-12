#include<stdio.h>
#include<iostream>
#include <queue>
#include <vector>
#include<queue>
#include<algorithm>

using namespace std;

int N, M, start;
int ans;

vector<int> v[101];
int check[101];

void search(int start)
{

	queue<int> q;
	q.push(start);
	

	while (1)
	{
		int now = q.front();
		q.pop();
		check[now] = 1;


		for (int i = 0; i < v[now].size(); i++)
		{

			if (check[v[now][i]] != 1)
			{
				check[v[now][i]] = 1;
				q.push(v[now][i]);
				ans++;
			}
			
		}


		if (q.empty())
		{
			printf("%d", ans);
			break;
		}



	}

}

int main()
{
	scanf("%d %d", &N, &M);
	start = 1;
	for (int i = 0; i < M; i++)
	{
		int temp1, temp2;

		scanf("%d %d", &temp1, &temp2);

		v[temp1].push_back(temp2);

		v[temp2].push_back(temp1);
	}

	search(start);

	return 0;
}