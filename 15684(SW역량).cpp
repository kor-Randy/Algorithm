#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

//(3,3)�� �Է����� ���� ��ٸ�(1)�� �־�����
//(3,2)���� 3�� ���� (3,4)���� 2�� ���� 
//1 : ���������� �̵� ,  2 : �������� �̵� , 3 : ��ٸ��� ���� ����
//������ (3,1)�� ���� ��ٸ�(1)�� ���� �Ǹ�
//(3,2)�� �������� �̵��ϴ� 2���� ���� �ϴµ� (3,3)������ 3�� �̹� ������.
//���� (3,2)�� 32�� �־� dfs�� �����ϰ� �ǵ��� ���� 3���� ���ư�
//(3,5)�� ���� ��ٸ�(1)�� �߰��ϴ� ��쿡�� ���������� (3,4)�� 3�� �־�������� �̹� 2�� ����
//���� (3,4)�� 23�� �־� dfs�� �����ϰ� �ǵ��� ���� 2�� ���ư�
//����, 23 32 2 ��� �������� �̵��ؾ� �ϱ⶧���� ������ ������ 2�� ���������� ����.

int N, M, H;
int arr[31][11];
int visit[31][11];
int res, cnt, temp;
void dfs(int ii, int jj)
{
	//printf("ii : %d , jj : %d , cnt : %d\n", ii, jj,cnt);
	if (jj == N)
	{
		dfs(ii + 1, 1);
		return;
	}

	if (cnt >= 4)
		return;

	bool flag=true;

	for (int i = 1; i <= N; i++)
	{
		int now = i;
		for (int j = 1; j <= H; j++)
		{
			if (arr[j][now] == 1)
			{
				now++;
			}
			else if (arr[j][now] == 2 || arr[j][now]==23 || arr[j][now]==32)
			{
				now--;
			}
		}
		if (now != i)
		{
			//�ϳ��� Ʋ����
			flag = false;
			break;
		}
	}

	if (flag == false)
	{
		//dfs�� �ؾ���
		
		for (int i = ii; i <= H; i++)
		{
			for (int j = 1; j < N; j++)
			{				
				//printf(" %d , %d �� ������ �ֳ�?\n", i, j);

				if (arr[i][j] == 0)
				{
					//printf("i : %d , j : %d arr[i][j] : %d �� ��ٸ� ����\n", i, j,arr[i][j]);

					
					cnt++;
					arr[i][j] = 1;
					if (j > 1 && j < N - 1)
					{
						if (arr[i][j - 1] == 2)
						{

							arr[i][j - 1] = 23;
						}
						else
						{
							arr[i][j - 1] = 3;
						}
						if (arr[i][j + 1] == 3)
							arr[i][j + 1] = 32;
						else
							arr[i][j + 1] = 2;
					}
					else if (j == 1)
					{
						if (arr[i][j + 1] == 3)
							arr[i][j + 1] = 32;
						else
							arr[i][j + 1] = 2;
					}
					else if (j == N - 1)
					{
						if (arr[i][j - 1] == 2)
						{

							arr[i][j - 1] = 23;
						}
						else
						{
							arr[i][j - 1] = 3;
						}
						if (arr[i][j + 1] == 3)
							arr[i][j + 1] = 32;
						else
							arr[i][j + 1] = 2;
					}

					
					dfs(i,j+1);

					cnt--;

					arr[i][j] = 0;
					if (j > 1 && j < N - 1)
					{
						if (arr[i][j - 1] == 23)
							arr[i][j - 1] = 2;
						else
							arr[i][j - 1] = 0;
						if (arr[i][j + 1] == 32)
							arr[i][j + 1] = 3;
						else
							arr[i][j + 1] = 0;
					}
					else if (j == 1)
						if (arr[i][j + 1] == 32)
							arr[i][j + 1] = 3;
						else
							arr[i][j + 1] = 0;
					else if (j == N - 1)
					{
						if (arr[i][j - 1] == 23)
							arr[i][j - 1] = 2;
						else
							arr[i][j - 1] = 0;
						if (arr[i][j + 1] == 32)
							arr[i][j + 1] = 3;
						else
							arr[i][j + 1] = 0;
					}
				}
			}
		}

	}
	else
	{
		res = min(res, cnt);
		return;
	}

}

int main()
{
	scanf("%d %d %d", &N, &M, &H);
	res = 100;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 1;//���μ��� �� �������� �߰� �Ұ���
		if (b > 1 && b < N - 1) 
		{
			if (arr[a][b - 1] == 2)
			{

				arr[a][b - 1] = 23;
			}
			else
			{
				arr[a][b - 1] = 3;
			}
			if (arr[a][b + 1] == 3)
				arr[a][b + 1] = 32;
			else
				arr[a][b + 1] = 2;
		}
		else if (b == 1)
		{
			if (arr[a][b + 1] == 3)
				arr[a][b + 1] = 32;
			else
				arr[a][b + 1] = 2;
		}
		else if (b == N - 1) 
		{
			if (arr[a][b - 1] == 2)
			{

				arr[a][b - 1] = 23;
			}
			else
			{
				arr[a][b - 1] = 3;
			}
			if (arr[a][b + 1] == 3)
				arr[a][b + 1] = 32;
			else
				arr[a][b + 1] = 2;
		}
	}

	
	dfs(1,1);
	if (res >= 4)
		printf("-1");
	else
		printf("%d", res);

	return 0;
}
