#include<stdio.h>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

int T,R,C;
int arr[51][51];
int temp[51][51];
int res, cnt,tmp,tmp1,tmp2;

int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
int xxx[4] = { 0,-1,0,1 };
int yyy[4] = { 1,0,-1,0 };
int check1, check2;
int x_1, y_1, x_2, y_2;
vector<int> vc;
void dust();
void up();
void down();
void simul()
{
	x_1 = vc[0];
	y_1 = 0;
	x_2 = vc[1];
	y_2 = 0;
	for (int i = 0; i < T; i++)
	{
		dust();
		up();
		down();
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			res += arr[i][j];
		}
	}
	res += 2;//공기청정기 -1 2개

}
void dust()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cnt = 0;
			if (arr[i][j] >= 5)
			{
				int d = arr[i][j] / 5;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + xx[k];
					int ny = j + yy[k];
					if (nx < 0 || nx>=R || ny < 0 || ny>=C || (nx==vc[0] && ny==0) || (nx==vc[1] && ny==0))
						continue;
					else
					{
						temp[nx][ny] += d;//인접 먼지 확산
						cnt++;
					}
				}

				temp[i][j] -= d*cnt;//자신 먼지 감소

			}
		}
	}
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			
				arr[i][j] += temp[i][j];
		}
	}
	memset(temp, 0, sizeof(temp));
}

void up()
{
	//0->1->2->3->0...
	int mx = vc[0];
	
	while (1)
	{
		
		
		int dx = xxx[check1];
		int dy = yyy[check1];

		x_1 = x_1 + dx;
		y_1 = y_1 + dy;
		//printf("up_x : %d , up_y : %d\n", x_1, y_1);
		if (x_1 == mx && y_1 == 0)
		{
			tmp1 = 0;
			check1 = 0;
			break;
		}
		else
		{
			tmp = arr[x_1][y_1];
			arr[x_1][y_1] = tmp1;
			tmp1 = tmp;
			tmp = 0;
		}

		if (x_1 == mx && y_1 == C - 1)
		{
			check1 = 1;
		}
		else if (x_1==0 && y_1 == C - 1)
		{
			check1 = 2;
		}
		else if (x_1 == 0 && y_1 == 0)
		{
			check1 = 3;
		}
		else if(x_1 == mx && y_1 == 0)
		{
			check1 = 0;
		}

		


	}

}

void down()
{
	//0->3->2->1->0...
	int mx = vc[1];
	while (1)
	{


		int dx = xxx[check2];
		int dy = yyy[check2];

		x_2 = x_2 + dx;
		y_2 = y_2 + dy;
		//printf("down_x : %d , down_y : %d\n", x_2, y_2);

		if (x_2 == mx && y_2 == 0)
		{
			tmp2 = 0;
			check2 = 0;
			break;
		}
		else
		{
			tmp = arr[x_2][y_2];
			arr[x_2][y_2] = tmp2;
			tmp2 = tmp;
			tmp = 0;
		}
		if (x_2 == mx && y_2 == C - 1)
		{
			check2 = 3;
		}
		else if (x_2 == R-1 && y_2 == C - 1)
		{
			check2 = 2;
		}
		else if (x_2 == R-1 && y_2 == 0)
		{
			check2 = 1;
		}
		else if (x_2 == mx && y_2 == 0)
		{
			check2 = 0;
		}




	}

}

int main()
{
	scanf("%d %d %d", &R, &C, &T);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == -1)
			{
				vc.push_back(i);
			}
		}
	}

	simul();
	printf("%d", res);
	return 0;
}
