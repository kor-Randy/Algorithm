#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

int N, L, R;
int arr[51][51];
int temp, res, cnt;
int visit[51][51];
int d[51][51];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int check;
void bfs(int, int);
void in();
int index;

void simul()
{
	while (1)
	{
		bool flag = false;
		index = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visit[i][j] == 0)
				{
					++index;
					temp = 0;
					cnt = 0;
					bfs(i, j);
					if(cnt>1)
					{
						flag = true;
						in();
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (d[i][j] != 0) {
					arr[i][j] = d[i][j];
					d[i][j] = 0;
				}
				visit[i][j] = 0;
			}
		}

		if (!flag)//종료조건
			break;
		else
			res++;

	}
}

void bfs(int sx, int sy)
{
	queue<pair<int, int>> q;
	q.push({ sx,sy });
	visit[sx][sy] = index;
	while (1)
	{
		int x = q.front().first;
		int y = q.front().second;
		int p = arr[x][y];
		q.pop();

		temp += arr[x][y];//연합의 인구
		cnt++;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			int np = arr[nx][ny];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visit[nx][ny]!=0)
				continue;
			else if(abs(p-np)>=L && abs(p-np)<=R)
			{
				//x,y의 갯수 추가
				check++;
				q.push({ nx,ny });
				visit[nx][ny] = index;
			}
		}

		if (q.empty())
			break;
	}


}

void in()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == index)
			{
				d[i][j] = temp / cnt;
			}

		}
	}

}

int main()
{
	scanf("%d %d %d", &N, &L, &R);
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}

	simul();

	printf("%d", res);

	return 0;
}
