#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

string arr[51];
int visit[51][51];
int N, M;
pair<int,int> s, d;
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
vector<pair<int, int>> water;

void bfs()
{
	queue<pair<int, int>> q;
	for (int i = 0; i < water.size(); i++)
	{
		q.push(water[i]);
		
	}
	if (q.empty())
		return;
	while (1)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M||visit[nx][ny]!=100000)
				continue;
			else
			{
				if (arr[nx][ny] == '.')
				{
					q.push({ nx,ny });
					visit[nx][ny] = visit[x][y] + 1;
				}
				

			}
		}
		if (q.empty())
			break;

	}


}

void gos()
{
	queue<pair<int, int>> q;
	q.push(s);

	while (1)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//printf("x : %d , y : %d %d√ \n", x, y,visit[x][y]);
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[x][y] + 1 >= visit[nx][ny])
				continue;
			else if (nx == d.first && ny == d.second)
			{
				printf("%d",visit[x][y]);
				return;
			}
			else
			{
				if (!(arr[nx][ny] == 'X'))
				{
					visit[nx][ny] = visit[x][y] + 1;
					q.push({ nx,ny });
				}
			}
		}
		if (q.empty())
		{
			printf("KAKTUS");
			return;
		}
	}

}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = 100000;

			if (arr[i][j] == 'D')
			{
				d = { i,j };
				visit[i][j] = 100000;
			}
			else if (arr[i][j] == 'S')
			{
				s = { i,j };
				visit[i][j] = 1;
			}
			else if (arr[i][j] == '*')
			{
				water.push_back({ i,j });
				visit[i][j] = 1;
			}
		}
	}
	bfs();

	
	gos();



	return 0;
}
