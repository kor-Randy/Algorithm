#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int N, M;
int arr[1001][1001];
int res, cnt, temp, visit[1001][1001][2];
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };

int bfs()
{
	queue<pair<pair<int, int>, int>> q;
	q.push({{ 1,1 }, 0});
	visit[1][1][0] = 1;
	visit[1][1][1] = 1;
	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second;
		q.pop();

		
		//printf("x : %d , y : %d , wall : %d , visit[x][y] : %d\n", x, y, wall,visit[x][y]);

		
		
			for (int i = 0; i < 4; i++)
			{
				int nx = x + xx[i];
				int ny = y + yy[i];

				if (nx<1 || nx>N || ny<1 || ny>M)
					continue;
				//범위를 넘거나 지금보다 짧게 갔던 곳이면 안간다.
				else
				{

					if (arr[nx][ny] == 1)
					{//앞이 벽이고
						if (wall == 0)
						{//벽을 한번도 부수지 않음
							q.push({ {nx,ny},1 });
							visit[nx][ny][1] = visit[x][y][wall] + 1;
						}
						else
						{//이미 벽을 한번 부숨
							continue;
						}
					}
					else
					{
						if (nx == N && ny == M)
							return visit[nx][ny][wall] = visit[x][y][wall] + 1;
						else if (visit[nx][ny][wall] == 1000001)
						{
							//벽이 아닌 곳에 간다.
							q.push({ { nx,ny },wall });
							visit[nx][ny][wall] = visit[x][y][wall] + 1;
						}
						
					}

				}

			
		}

			

	}
	return -1;


}

int main()
{
	scanf("%d %d", &N, &M);

	string str;

	for (int i = 1; i <= N; i++)
	{
		cin >> str;
		for (int j = 1; j <= M; j++)
		{
			arr[i][j] = str[j - 1] - '0';
			visit[i][j][0] = visit[i][j][1] = 1000001;
			//printf("%c", arr[i][j]);
		}
		//printf("\n");
	}

	bfs();
	res = min(visit[N][M][0], visit[N][M][1]);
	if (res != 1000001)
		printf("%d", res);
	else
		printf("-1");
	


	return 0;
}
