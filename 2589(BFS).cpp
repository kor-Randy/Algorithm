#include<stdio.h>
#include<iostream>
#include<queue>

using namespace std;

char arr[51][51];
int N, M;
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int check[51][51];
int visit[51][51];
int res;
void bfs(int a,int b)
{
	queue<pair<int,int>> q;
	q.push({ a,b });
	check[a][b] = 0;

	while (1)
	{
		int x = q.front().first;
		int y = q.front().second;
		char v = arr[x][y];
		q.pop();
		//printf("x = %d , y = %d , check[x][y] = %d\n", x, y, check[x][y]);
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			char nv = arr[nx][ny];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M || nv=='W')
				continue;
			else
			{
				if (check[nx][ny] == 0)
				{
					check[nx][ny] = check[x][y] + 1;
					q.push({ nx,ny });
				}
				else
				{
					check[nx][ny] = min(check[nx][ny],check[x][y] + 1);
				}
				res = max(res, check[nx][ny]);
			}

		}
		if (q.empty())
			break;

	
	}


}

void clear()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			check[i][j] = 0;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &arr[i]);

	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'W')
				continue;
			else
			{
			
				bfs(i, j);
				clear();
			}

			
		}
	}

	printf("%d", res);

	return 0;
}
