#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

int N, K;
int arr[200001];
int visit[200001];
int res;
int temp;
int bfs(int n)
{
	queue<int> q;

	q.push(n);
	visit[n] = 1;
	if (K <= N)
	{
		return N-K;
	}
	else
	{
		while (1)
		{
			int now = q.front();
			q.pop();

			for (int i = 0; i < 3; i++)
			{
				switch (i)
				{
					case 0:
					{
						temp = now - 1;
						if (temp >=0 && temp <= 100000)
						{
							if (visit[temp] == 0)
							{
								q.push(temp);
								arr[temp] = arr[now] + 1;
								visit[temp] = 1;
							}
							
						}
						break;
					}
					case 1:
					{
						temp = now + 1;
						if (temp >= 0 && temp <= 100000)
						{
							if (visit[temp] == 0)
							{
								q.push(temp);
								arr[temp] = arr[now] + 1;
								visit[temp] = 1;
							}
							
						}
						break;
					}
					case 2:
					{
						temp = now * 2;
						if (temp >= 0 && temp<=100000)
						{
							if (visit[temp] == 0)
							{
								q.push(temp);
								arr[temp] = arr[now] + 1;
								visit[temp] = 1;
							}
							
						}
						break;
					}
				}//switch
			}//for


			if (now == K)
				return arr[now];

		}
	}
	


}


int main()
{
	scanf("%d %d", &N, &K);

	

	printf("%d", bfs(N));

	return 0;
}