#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[17][17];
int d[17][17];
int xx[3][3] = { {0,0,1} ,{0,1,1},{0,1,1} };
int yy[3][3] = { {1,0,1},{0,0,1},{1,0,1} };//���� ���� �밢��

void dfs(int x, int y,int state)// 0->���� , 1->���� , 2->�밢��
{//x,y�� �������� �� ��ġ
	if (x == N - 1 && y == N - 1)
	{
		d[x][y]++;
		return;
	}
	else
	{
			for (int i = 0; i < 3; i++)
			{
				int nx = x + xx[state][i];
				int ny = y + yy[state][i];
				if (arr[nx][ny] != 0 || nx>=N||ny>=N || (nx==x && ny==y))
				{//���̰ų� �Ѿ ���
					//��ġ�� ���� ���
				
					continue;
				}
				else if (i == 0)
				{//���η� ����
					dfs(nx, ny, 0);
				}
				else if (i == 1)
				{//���η� ����
					dfs(nx, ny, 1);
				}
				else if(i==2)
				{//�밢������ ����
					if (arr[x + 1][y] != 0 || arr[x][y + 1] != 0 || arr[x + 1][y + 1] != 0)
						continue;
					else
					{
						dfs(nx, ny, 2);
					}
					
				}
			}
		
		

	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);


	dfs(0, 1, 0);
	printf("%d", d[N-1][N-1]);

	return 0;
}
