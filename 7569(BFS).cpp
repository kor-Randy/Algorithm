#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//0인데 주변이 -1로 쌓여있다 -> return -1;
//-1이면 넘어간다
//1이면 주변을 1로 만든다
int N, M, H;
int arr[101][101][101];
int d[101][101][101];
int xx[6] = { -1,1,0,0,0,0 };
int yy[6] = { 0,0,-1,1,0,0 };
int zz[6] = { 0,0,0,0,-1,1 };
int res, temp, cnt;
int zero;
int ma;
queue<pair<int, pair<int, int>>> q;
int bfs()
{
	if (q.empty())//1이 없다
		return -1;
	else if (zero == 0)//0이 없다
		return 0;
	else 
	{
		while (1)
		{
			int x = q.front().first;
			int y = q.front().second.first;
			int z = q.front().second.second;
			q.pop();

			for (int i = 0; i < 6; i++)
			{//6방향 돌면서 익힌다.
				int nx = x + xx[i];
				int ny = y + yy[i];
				int nz = z + zz[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
					continue;
				else
				{
					if (arr[nx][ny][nz] == 0)//익지않은 토마토를 익히고 q에 삽입
					{
						arr[nx][ny][nz] = 1;
						zero--;//0의 갯수 --;
						d[nx][ny][nz] = d[x][y][z] + 1;//현재 익게 되는 토마토의 날짜
						ma = max(ma, d[nx][ny][nz]);//최종 며칠이 걸렸는지 확인 위함
						q.push({ nx,{ny,nz} });
					}
				}

			}

			if (q.empty())
				break;


		}

		if (zero > 0)//전이가 끝났는데 0이 존재
			return -1;
		else//전이가 끝남 -> 걸린 날짜 return
			return ma;

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
				if (arr[j][k][i] == 0)
					zero++;
				else if (arr[j][k][i] == 1)
				{
					q.push({ j,{k,i} });
				}
			}
		}
	}

	printf("%d", bfs());

	return 0;
}
