#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
//1. visit을 하나로 둬서 blue가 갔던 곳을 red가 가도 visit으로 봤기떄문에 트림
//2. visit을 visitr과 visitb로 둬서 red와 blue가 이전에 한번이라도 갔으면 동시에 같은 곳에 가지 않아도 visit으로 봤기때문에 틀림

int N, M;
char arr[11][11];
char tt;
int visit[11][11][11][11];
int cc[11][11];
int res, cnt, temp;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
pair<int, int> hall,red,blue;
int rm, bm;
int dr, db,v;

int bfs()
{
	res = 100;
	queue<pair<pair<int, int>, int>> rq;
	queue<pair<int, int>> bq;

	rq.push({red,0});
	bq.push(blue);
	visit[red.first][red.second][blue.first][blue.second] = 1;

	while (1)
	{
		int rx = rq.front().first.first;
		int ry = rq.front().first.second;
		int c = rq.front().second;
		int bx = bq.front().first;
		int by = bq.front().second;
		rq.pop();
		bq.pop(); 
		visit[rx][ry][bx][by] = 1;
		
		//printf("\nrx : %d ry : %d bx : %d by : %d c : %d\n\n", rx, ry, bx, by,c);
		
		if (c >= 10)
		{
			if (res <= 10)
				return res;
			else
				return -1;
		}

		for (int i = 0; i < 4; i++)
		{
			rm = bm = v = dr = db = 0;
			int nrx, nry, nbx, nby;
			for (int j = 1; j < 10; j++)
			{
				nrx = rx + xx[i] * j;
				nry = ry + yy[i] * j;
				rm++;
				
				
				if (arr[nrx][nry] == '#')
				{
					nrx = nrx - xx[i];
					nry = nry - yy[i];
					
					
					break;
					
				}
				else if (arr[nrx][nry] == 'O')
				{
					dr = 1;
					break;
				}
			}//red

			for (int j = 1; j < 10; j++)
			{
				nbx = bx + xx[i] * j;
				nby = by + yy[i] * j;
				bm++;

				if (arr[nbx][nby] == '#')
				{
					nbx = nbx - xx[i];
					nby = nby - yy[i];
					
					
					break;

				}
				else if (arr[nbx][nby] == 'O')
				{
					db = 1;
					break;
				}
			}//blue

			if (nrx == nbx && nry == nby)
			{
				if (rm > bm)
				{
					nrx = nrx - xx[i];
					nry = nry - yy[i];
				}
				else
				{
					nbx = nbx - xx[i];
					nby = nby - yy[i];
				}
				
			}

			if (visit[nrx][nry][nbx][nby] != 0)
			{
				v = 1;
			}

			if (db == 1) continue;
			else
			{
				if (dr == 1)
				{
					res = min( res,c+1);
					continue;
				}
				else
				{
					
					if (v == 1) // 두군데 모두 갔던 곳임
					{
						continue;
					}
					else  // 한군데라도 새로 간곳이 있음
					{

						
						rq.push({ { nrx,nry },c + 1 });
						bq.push({ nbx,nby });

						
						
						
					}
				}
			}

			
		
		}

		
		if (rq.empty())
		{
			//printf("끝남");
			if (res <= 10)
				return res;
			else
				return -1;
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
	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'O')
			{
				hall = { i,j };
			}
			else if (arr[i][j] == 'R')
			{
				arr[i][j] = '.';
				red = { i,j };
			}
			else if (arr[i][j] == 'B')
			{
				arr[i][j] = '.';
				blue = { i,j };
			}
		}
	
	
	printf("%d", bfs());


	return 0;
}
