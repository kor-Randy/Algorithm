#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

int N, M, D;
int ar[16][16];
int arr[16][16];
int visit[16][16];
vector<int> archor;
int res, cnt, temp;
int xx[3] = { 0,-1,0 };
int yy[3] = { -1,0,1 };//왼쪽 위 오른쪽
vector<int> vc;
int d;

int dfs(int x, int y)
{
	if (arr[x][y] != 0)
	{
		arr[x][y]--;
		return 1;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			else
			{
				if (dfs(nx, ny) == 1)
					return 1;
				
			}
		}
	}
	return 0;
}

void bfs(int n,int num)
{
	queue<pair<int, int>> q;
	
	q.push({ n,num });

	
	while (1)
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		
		
		if (arr[x][y] != 0)
		{
			//거리 1짜리
			//printf("x : %d , y : %d 죽음\n", x, y);
			arr[x][y]--;
			return;
		}
		else if(visit[x][y]+1<=D)
		{
			//쏠 수 있는 거리일 때
			//바로 앞에 적이 없으면
			for (int i = 0; i < 3; i++)
			{
				int nx = x + xx[i];
				int ny = y + yy[i];

				if (nx < 0 || nx >= N || ny < 0 || ny >= M)
					continue;
				else
				{
					
					if (arr[nx][ny] != 0)
					{
						//적이 있을 때
					//	printf("nx : %d ,ny : %d 죽음\n", nx, ny);
						arr[nx][ny]--;
						return;
					}
					else
					{
						visit[nx][ny] = visit[x][y] + 1;
						q.push({ nx,ny });
					}

				}

			}
		}
		else
		{
			//쏠 수 없는 거리이다.	
		}

		if (q.empty())
		{
			//printf("하나도 못 지움\n", n);
			break;
		}

	}


}

void combi(int c, int index)
{
	
	if (c == 3)
	{
	
		//printf("%d %d %d\n", archor[0], archor[1], archor[2]);
		cnt = 0;
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				arr[j][k] = ar[j][k];
				visit[j][k] = 1;
			}
		}

		for (int i = N - 1; i >= 0; i--)
		{
			for (int k = 0; k < M; k++)
			{
				visit[i][k] = 1;
			}
			
			for (int j = 0; j < 3; j++)
			{
				bfs(i,archor[j]);
			
			}


			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					if (arr[j][k] != ar[j][k])
						arr[j][k] = 0;
				}
			}

		}

		for (int i = 0; i <N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] != ar[i][j])
					cnt++;
			}
		}
		//printf("cnt : %d\n", cnt);
		res = max(res, cnt);
		return;
	}
	else
	{
		for (int i = index; i < N; i++)
		{
			archor.push_back(i);
			combi(c + 1, i + 1);
			archor.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d %d", &N, &M, &D);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &ar[i][j]);
			if (ar[i][j] == 1)
				ar[i][j] = 3;
		}
	}


	/*do {
		archor.clear();
		archor.push_back(vc[0]);
		archor.push_back(vc[1]);
		archor.push_back(vc[2]);
		cnt = 0;
		for (int i = N - 1; i >= 0; i--)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < M; k++)
				{
					visit[i][j] = 1;
				}
			}
			bfs(i);
		
		}

		res = max(res, cnt);


	} while (next_permutation(vc.begin(), vc.end()));*/

	combi(0, 0);

	printf("%d", res);



	return 0;
}
