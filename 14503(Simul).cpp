#include<stdio.h>
#include<iostream>
using namespace std;

int N, M;
int arr[52][52];
int cnt, res, temp;
int r, c, d;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };
int le[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
// 0 -> 0,-1��  1 -> 1,0��  2 -> 0,1��  3 -> -1,0��
void simul(int x, int y,int d)
{
	
	while (1)
	{

		int nx = x + le[d][0];
		int ny = y + le[d][1];//�� ���� ���ʹ���
	
		

	//	printf("������ġ : (%d,%d)      ������ġ : (%d,%d)    ���¹��� : %d\n", x, y, nx, ny,d);

		

		if (arr[x][y] == 0)
		{
			//printf("û��\n");
			arr[x][y] = 2;
			res++;
			cnt = 0;
			
		}
		
		
		if (arr[nx][ny] == 0)
		{
			d = (d + 3) % 4;//�������� ����
			x += xx[d];
			y += yy[d]; //������ �̵�
		}
		else
		{
			//printf("cnt++    cnt : %d\n",cnt);
			d = (d + 3) % 4;//�������� ����
			cnt++;
			
		}

		if (cnt == 4)
		{
			int bd = (d + 2) % 4;
			int bx = x + xx[bd];
			int by = y + yy[bd];

			if (arr[bx][by] == 1)
			{
			//	printf("�ڰ� ���̾�\n");
				break;
			}
			else if (arr[bx][by] == 2)
			{
				//printf("�ڷ���ĭ\n");
				x = bx;
				y = by;
				cnt = 0;
			}
			else
			{
				//printf("����ֿ� ����� �ڿ��� ����µ�\n");
			}
		}

	}

}

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &d);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			
		}
	}
	for (int i = 0; i < M; i++)
	{
		arr[0][i] = 1;
		arr[N + 1][i] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		arr[i][0] = 1;
		arr[i][M + 1] = 1;
	}

	simul(r, c,d);

	printf("%d", res);

	return 0;
}
