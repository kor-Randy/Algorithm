#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int N, M;
string str[101];
int res, temp, cnt;
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int visit[101][101];

void bfs(int x, int y)
{
	priority_queue<pair<int,pair<int, int>>> q;
	q.push({ str[x][y]-'0',{x,y} });
	visit[x][y] = 0;
	while (1)
	{

		x = q.top().second.first;
		y = q.top().second.second;
		int c = - q.top().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];


			
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			else
			{

				

				int nc = str[nx][ny] - '0';
				if (nc == 0)
				{
					if (visit[nx][ny] > visit[x][y] || visit[nx][ny] == -1)
					{
						visit[nx][ny] = visit[x][y];
						q.push({ -nc,{nx,ny} });
					}
				}
				else
				{
					if (visit[nx][ny] > visit[x][y]+1 || visit[nx][ny] == -1)
					{
						visit[nx][ny] = visit[x][y]+1;
						q.push({ -nc,{ nx,ny } });
					}
				}



			}

		}

		if (q.empty())
			break;


	}

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = -1;
		}
	}

	bfs(0, 0);
	cout << visit[N - 1][M - 1];


	return 0;
}