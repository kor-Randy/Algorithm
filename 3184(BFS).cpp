#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int R, C;
char arr[251][251];
int check[251][251];
int x[4] = { -1,0,1,0 };
int y[4] = { 0,-1,0,1 };
int res, cnt;
int sheep, wolf;
int res_sheep, res_wolf;
void bfs()
{

	queue<pair<int,int>> q;
	
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{

			if (check[i][j] == 1)
			{
				continue;
			}
			else
			{
				wolf = sheep = 0;
				
				

				check[i][j] = 1;

				if (arr[i][j] != '#')
				{
					q.push({ i,j });

					while (1)
					{
						int r = q.front().first;
						int c = q.front().second;
						q.pop();
						if (arr[r][c] == 'v')
							wolf++;
						else if (arr[r][c] == 'o')
							sheep++;

						for (int i = 0; i < 4; i++)
						{
							int nr = r + x[i];
							int nc = c + y[i];

							if (nr < 0 || nr >= R || nc < 0 || nc >= C)
							{
								continue;
							}
							else
							{
								if (check[nr][nc] == 0)
								{
									if (arr[nr][nc] != '#')
									{
										q.push({ nr,nc });
										check[nr][nc] = 1;
									}
									else
									{
										check[nr][nc] = 1;
									}

								}
								else
								{
									//next가 이미 갔던 곳
								}
							}
						}


						if (q.empty())
						{
							
							break;
						}
					}
				}


				if (sheep > wolf)
				{
					res_sheep += sheep;
				}
				else
				{
					res_wolf += wolf;
				}
			}
		}
	}

}

int main()
{
	scanf("%d %d", &R, &C);

	getchar();
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%c", &arr[i][j]);
		}
		getchar();
	}

	bfs();

	printf("%d %d", res_sheep, res_wolf);

	return 0;
}
