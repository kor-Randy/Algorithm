#include<stdio.h>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, K;
int arr[101][101];
int visit[101][101];
int xx[2],yy[2];
int res;
int cnt;
int x[4] = { 0,-1,0,1 };
int y[4] = { -1,0,1,0 };
vector<int> vc;


void bfs()
{

	queue<pair<int, int>> q;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 0 && visit[i][j]==0)
			{
				q.push({ i,j });
				visit[i][j] = 1;
				
				cnt = 1;
				while (1)
				{
					
					pair<int, int> now = q.front();
					q.pop();

					for (int k = 0; k < 4; k++)
					{
						if (now.first + x[k] < 0 || now.first + x[k] >= M || now.second + y[k] < 0 || now.second + y[k] >= N)
							continue;
						else
						{
							if (visit[now.first + x[k]][now.second + y[k]] == 0 && arr[now.first + x[k]][now.second + y[k]] == 0)
							{
								cnt++;
								q.push({now.first+x[k],now.second+y[k]});
								visit[now.first + x[k]][now.second + y[k]] = 1;
							}
						}

					}

					if (q.empty())
					{
						res++;
						vc.push_back(cnt);
						break;

					}
					
				}

			}
		}
	}

}

int main()
{
	scanf("%d %d %d", &M, &N, &K);

	for (int i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &yy[0], &xx[0], &yy[1], &xx[1]);

		for (int j = xx[0]; j < xx[1]; j++)
		{
			for (int k = yy[0]; k < yy[1]; k++)
			{
				arr[j][k] = 1;
				
			}
		}

	}

	

	bfs();

	sort(vc.begin(), vc.end());

	printf("%d\n", res);

	for (int i = 0; i < vc.size(); i++)
		printf("%d ", vc[i]);


	return 0;
}
