#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N;

int arr[101][101];
int res, temp, cnt;
int f[101][101];
int visit[101][101];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };

void find(int x, int y)
{
	if (f[x][y] != 0)
		return;

	queue<pair<int, int>> q;
	q.push({ x,y });
	f[x][y] = cnt;


	while (1)
	{
		int x = q.front().first;
		int y = q.front().second;
		
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || f[nx][ny]!=0)
				continue;
			else
			{
				if (arr[nx][ny] == 1)
				{
					f[nx][ny] = cnt;//¼¶¹øÈ£ Àû±â
					q.push({ nx,ny });
				}
			}

		}

		if(q.empty())
		{
			cnt++;
			break;
		}
		
	}

}

void bfs(int num)
{
	queue<pair<int, int>> q;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (f[i][j] == num)
			{
				q.push({ i,j });
				arr[i][j] = 0;
			}
		}
	}



	while (1)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		//printf("x : %d , y : %d\n", x, y);

		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[nx][ny]!=-1 || arr[x][y]>=res)
				continue;
			else
			{
				if (f[nx][ny] == 0)
				{
					if (!(arr[x][y] + 1 >= res))
					{
						arr[nx][ny] = arr[x][y] + 1;
						q.push({ nx,ny });
					}
				}
				
				else
				{
					//´Ù¸¥ ¼¶¿¡ µµÂø
					//printf("\nres : %dµµÂø\n", res);
					
					res = min(res, arr[x][y]);
					return;
				}
			}
		}

		if (q.empty())
			break;

	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	cnt = 1;
	res = 1000000;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			
			if (arr[i][j] == 1)
				find(i, j);
		}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		{
			arr[i][j]=-1;
		}
	}
	

	for (int i = 1; i < cnt; i++){
		
		bfs(i);
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
				arr[j][k] = -1;
		}

}



	printf("%d", res);


	return 0;
}
