#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int arr[101][101][101];
int res, temp, cnt;
int N, M, H;
queue<pair<pair<int, int>, int>> q;
int xx[6] = { 0,0,0,0,1,-1 };
int yy[6] = { 0,0,-1,1,0,0 };
int zz[6] = { -1,1,0,0,0,0 };

void bfs()
{
	
	while (1)
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		//printf("x : %d , y : %d , z : %d\n", x, y, z);

		for (int i = 0; i < 6; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			int nz = z + zz[i];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H)
				continue;
			else
			{
				if (arr[nx][ny][nz] == 0)
				{
					arr[nx][ny][nz] = arr[x][y][z] + 1;
					res = arr[nx][ny][nz];
					q.push({ {nx,ny},nz });
					cnt--;
				}
			}
		}

		if (q.empty())
			break;

	}

}

int main()
{
	scanf("%d %d %d", &M, &N, &H);

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				scanf("%d", &arr[j][k][i]);
				if (arr[j][k][i] == 1)
					q.push({ {j,k},i });
				else if (arr[j][k][i] == 0)
					cnt++;
			}
		}
	}
	if (cnt == 0)
	{
		printf("0");
		return 0;
	}
	bfs();

	

	if (cnt == 0)
		printf("%d", res-1);
	else
		printf("-1");


	return 0;
}
