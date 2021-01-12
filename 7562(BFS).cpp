#include<stdio.h>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N, T;
int res, temp, cnt;
pair<int, int> start;
pair<int, int> des;
int check[301][301];
int d[301][301];
int xx[8] = { -2,-2,-1,-1,1,1,2,2 };

int yy[8] = {-1,1,-2,2,-2,2,-1,1};

void bfs()
{
	
	queue<pair<int, int>> q;
	q.push(start);

	while (1)
	{
		int x = q.front().first;
		int y = q.front().second;
		check[x][y] = 1;
		q.pop();
		
		//printf("x : %d y : %d\n", x, y);

		if (x == des.first && y == des.second)
		{
			break;
		}
		for (int i = 0; i < 8; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			//printf("nx : %d ny : %d\n", nx, ny);
			if (check[nx][ny]!=0 || nx<0||nx>=N||ny<0||ny>=N)
			{
				continue;
			}
			else
			{
				q.push({ nx,ny });
				check[nx][ny] = 1;
				d[nx][ny] = d[x][y] + 1;
			}

		}


	}

}

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		int a, b;
		scanf("%d", &N);

		scanf("%d %d", &a, &b);
		start={ a,b };
		scanf("%d %d", &a, &b);
		des = { a,b };
		//printf("%d %d %d %d", start.first, start.second, des.first, des.second);
		bfs();
		printf("%d\n", d[des.first][des.second]);
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				check[j][k] = 0;
				d[j][k] = 0;
			}
		}

	}

	return 0;

}
