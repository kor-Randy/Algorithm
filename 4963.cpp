#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int arr[51][51];
int visit[51][51];
int w, h;
int temp, res;
int xx[8] = { -1,-1,-1,0,0,1,1,1 };
int yy[8] = { -1,0,1,-1,1,-1,0,1 };

void bfs(int a, int b)
{
	queue<pair<int,int>> q;

	if (visit[a][b] == 1 || arr[a][b]==0)
		return;
	else
	{
		q.push({ a,b });
		visit[a][b] = 1;

		while (1)
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			//printf("\n현재위치 : %d %d \n", x, y);

			for (int i = 0; i < 8; i++)
			{
				int nx = x + xx[i];
				int ny = y + yy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (arr[nx][ny] == 1 && visit[nx][ny] == 0)
				{
					q.push({ nx,ny });
					visit[nx][ny] = 1;
				}

			}


			if (q.empty())
			{
				res++;
				break;
			}
		}
	}
}

int main()
{
	while (1)
	{

		scanf("%d %d", &w, &h);
	
		if (w == 0 && h == 0)
			break;
		else
		{
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					scanf("%d", &arr[i][j]);
				}
			}

			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					bfs(i,j);
				}
			}

			printf("%d\n", res);
			res = 0;
			
			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					visit[i][j] = 0;
				}
			}
		}
	}

	return 0;
}
