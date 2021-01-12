#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int N, M;
string str[51];
int visit[51][51];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int res;
void bfs(int x, int y)
{
	int cnt = 0;
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = 1;

	while (1)
	{
		x = q.front().first;
		y = q.front().second;
		char c = str[x][y];
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M||visit[nx][ny]!=0)
				continue;
			else
			{
				char nc = str[nx][ny];

				if (nc == 'W')
					continue;
				else
				{
					visit[nx][ny] = visit[x][y]+1;
					q.push({ nx,ny });
					cnt = visit[nx][ny];
				}

			}

		}

		if (q.empty())
		{
			res = max(res, cnt);
			break;
		}


	}

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (str[i][j]=='L')
			{
				bfs(i, j);

				for (int k = 0; k < N; k++)
				{
					for (int l = 0; l < M; l++)
					{
						visit[k][l] = 0;
					}
				}

			}
		}
	}

	cout << res-1;

	return 0;
}
