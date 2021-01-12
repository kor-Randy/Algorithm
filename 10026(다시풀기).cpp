#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int N;
string str[101];
int visit[101][101];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int a, b;
int res, cnt1,cnt2, temp;
void bfs(int x, int y, int ver)
{
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
			
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny]!=0)
				continue;
			else
			{
				int nc = str[nx][ny];
				if (ver == 1)
				{
					if (c == nc)
					{
						visit[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				else
				{
					if ((c == 'R'&&nc == 'G') || (c == 'G'&&nc == 'R') || (c==nc))
					{
						visit[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
				
			}

		}


		if (q.empty())
		{
			if (ver == 1)
				cnt1++;
			else
				cnt2++;
			break;
		}
	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		cin >> str[i];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(visit[i][j]==0)
				bfs(i, j, 1);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0)
				bfs(i, j, 2);
		}
	}

	printf("%d %d", cnt1, cnt2);

	return 0;
}
