#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, L;
int arr[101][101];
int xx[101][101];
int yy[101][101];
int res, cnt, temp;

void checkx(int x)
{
	int leng = 1;
	for (int i = 0; i < N-1; i++)
	{
		//printf("i = %d\n", i);
		if (arr[x][i] == arr[x][i + 1])
		{
			//����
			leng++;
		}
		else if (arr[x][i] + 1 == arr[x][i + 1])
		{
			//���� 1���� ��
			if (leng >= L)
			{
				int c = 0;
				//���� ���� ��
				if (L == 1)
				{
					if (xx[x][i] == 1)
						return;
					else
					{
						leng = 1;
						xx[x][i] = 1;
					}

				}
				else
				{
					for (int j = i - L + 1; j <= i; j++)
					{
						if (xx[x][j] == 1)
						{
							c = 1;
							return;
						}
					}
					if (c == 0)
					{
						leng = 1;
						for (int j = i - L + 1; j <= i; j++)
						{
							xx[x][j] = 1;
						}
					}
					else
						return;
				}
				
			}
			else
			{
				//���� ���� �ȵ�
				return;
			}
		}
		else if (arr[x][i] - 1 == arr[x][i + 1])
		{
			int c = 0;
			// 1 ����
			if (i + L <= N - 1)
			{
				for (int j = i + 1; j < i + L; j++)
				{
					if (arr[x][j] != arr[x][j + 1])
					{
						c = 1;
						return;
					}
				}
				if (c == 1)
				{
					return;
				}
				else
				{
					if (L == 1)
					{
						xx[x][i+1] = 1;
					}
					//printf("�������濡 ���� i : %d -> %d\n", i, i + L-1);
					else
					{
						for (int j = i + 1; j <= i + L; j++)
						{
							xx[x][j] = 1;
						}
						i = i + L - 1;
					}
				}
			}
			else
				return;
		}
		else
			return;
		
		if (i == N - 2)
		{
			//printf("x : %d \n", x);
			res++;
		}

	}


}

void checky(int y)
{

	int leng = 1;
	for (int i = 0; i < N - 1; i++)
	{
		//printf("i = %d\n", i);

		if (arr[i][y] == arr[i+1][y])
		{
			//����
			leng++;
		}
		else if (arr[i][y] + 1 == arr[i + 1][y])
		{
			//���� 1���� ��
			if (leng >= L)
			{
				int c = 0;
				//���� ���� ��
				if (L == 1)
				{
					if (yy[i][y] == 1)
						c = 1;
					
					if(c==1)
					{
						return;
					}
					else
					{
						leng = 1;
						yy[i][y] = 1;
					}
				}
				else
				{
					for (int j = i - L + 1; j <= i; j++)
					{
						if (yy[j][y] == 1)
						{
							c = 1;
							return;
						}
					}
					if (c == 0)
					{
						leng = 1;
						for (int j = i - L + 1; j <= i; j++)
						{
							yy[j][y] = 1;
						}
						//	printf("�������濡 ���� i : %d\n", i);
					}
					else
						return;
				}

			}
			else
			{
				//���� ���� �ȵ�
				return;
			}
		}
		else if(arr[i][y]-1 == arr[i+1][y])
		{
			//����
			int c = 0;
			// 1 ����
			if (i + L <= N - 1)
			{
				for (int j = i + 1; j < i + L; j++)
				{
					if (arr[j][y] != arr[j+1][y])
					{
						c = 1;
						return;
					}
				}
				if (c == 1)
				{
					return;
				}
				else
				{
					if (L == 1)
					{
						yy[i+1][y] = 1;
					}
					//printf("�������濡 ���� i : %d -> %d\n", i, i + L-1);
					else
					{
						//printf("�������濡 ���� i : %d -> %d\n", i, i + L - 1);
						for (int j = i + 1; j <= i + L; j++)
						{
							yy[j][y] = 1;
						}
						i = i + L - 1;
						
					}
				}
			}
			else
				return;
		}

		else
			return;
		if (i == N - 2)
		{
			//printf("y : %d\n", y);
			res++;
		}

	}


}

int main()
{
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		checkx(i);
	}//���� �� y=0

	for (int i = 0; i < N; i++)
	{
		checky(i);
	}//���� �� x=0

	printf("%d", res);

	return 0;
}
