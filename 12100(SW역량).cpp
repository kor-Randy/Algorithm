#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

int res, cnt;
void merge(int c, int d, int ori[21][21]);
void dfs(int c,int arr[21][21])
{

	if (c == 5)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				res = max(res, arr[i][j]);
			}
		}
		return;
	}

	int ori[21][21];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			ori[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		merge(c,i,arr);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				arr[i][j] = ori[i][j];
			}
		}
	}

}

void merge(int c,int d,int ori[21][21])
{

	int temp[21][21] = {0,};
	
	if (d == 0)
	{
		//상
		for (int i = 0; i < N; i++)
		{
			int tempIndex = 0;

			for (int j = 0; j < N; j++)
			{
				int pick = 0;
				int next = 0;
				if (ori[j][i] == 0)
					continue;
				else
				{
					pick = j;
					next = pick + 1;
				}
				while (1)
				{
					if (ori[next][i] != 0 || next>=N)
						break;
					next++;
				}

				if (ori[j][i] == ori[next][i] && pick!=N-1)
				{
					//아래것이랑 같은 경우
					//자신이 0이 아닌 경우
					//printf("윗방향 %d,%d 값와 아래값 : %d 같음\n", j, i,ori[j][i]);
					temp[tempIndex][i] = ori[pick][i] * 2;
					tempIndex++;
					ori[next][i] = 0;
					j=next;
				}
				else
				{
					//아래것이랑 다른 경우
					temp[tempIndex][i] = ori[j][i];
					tempIndex++;
				}

			}

			if (tempIndex != N)
			{
				for (int j = tempIndex; j < N; j++)
				{
					temp[j][i] = 0;
				}
			}

		}
		

	}
	else if (d == 1)
	{
		//우
		for (int i = 0; i < N; i++)
		{
			int tempIndex = N-1;

			for (int j = N-1; j >=0 ; j--)
			{
				int pick = 0;
				int next = 0;
				if (ori[i][j] == 0)
					continue;
				else
				{
					pick = j;
					next = pick - 1;
				}
				while (1)
				{
					if (ori[i][next] != 0 || next <0)
						break;
					next--;
				}

				if (ori[i][pick] == ori[i][next] && pick!=0)
				{
					//아래것이랑 같은 경우
					//자신이 0이 아닌 경우
					temp[i][tempIndex] = ori[i][pick] * 2;
					tempIndex--;
					ori[i][next] = 0;
					j=next;
				}
				else
				{
					//아래것이랑 다른 경우
					temp[i][tempIndex] = ori[i][pick];
					tempIndex--;
				}

			}

			if (tempIndex != -1)
			{
				for (int j = tempIndex; j >=0 ; j--)
				{
					temp[i][j] = 0;
				}
			}

		}
	}
	else if (d == 2)
	{
		//하
		for (int i = 0; i < N; i++)
		{
			int tempIndex = N-1;

			for (int j = N-1; j >= 0; j--)
			{
				int pick = 0;
				int next = 0;
				if (ori[j][i] == 0)
					continue;
				else
				{
					pick = j;
					next = pick - 1;
				}
				while (1)
				{
					if (ori[next][i] != 0 || next <0)
						break;
					next--;
				}

				if (ori[pick][i] == ori[next][i] && pick != 0)
				{
					//자신이 0이 아닌 경우
					temp[tempIndex][i] = ori[pick][i] * 2;
					tempIndex--;
					ori[next][i] = 0;
					j=next;
				}
				else
				{
					//아래것이랑 다른 경우
					temp[tempIndex][i] = ori[pick][i];
					tempIndex--;
				}

			}

			if (tempIndex != -1)
			{
				for (int j = tempIndex; j >=0 ; j--)
				{
					temp[j][i] = 0;
				}
			}

		}
	}
	else
	{
		//좌
		for (int i = 0; i < N; i++)
		{
			int tempIndex = 0;

			for (int j = 0; j < N ; j++)
			{
				int pick = 0;
				int next = 0;
				if (ori[i][j] == 0)
					continue;
				else
				{
					pick = j;
					next = pick + 1;
				}
				while (1)
				{
					if (ori[i][next] != 0|| next>=N)
						break;
					next++;
				}
				if (ori[i][pick] == ori[i][next] && pick!=N-1)
				{
					//아래것이랑 같은 경우
					//자신이 0이 아닌 경우
					
					

					temp[i][tempIndex] = ori[i][pick] * 2;
					tempIndex++;
					ori[i][next] = 0;
					j=next;
				}
				else
				{
					//아래것이랑 다른 경우
					temp[i][tempIndex] = ori[i][pick];
					tempIndex++;
				}

			}

			if (tempIndex != N)
			{
				for (int j = tempIndex; j <N ; j++)
				{
					temp[i][j] = 0;
				}
			}

		}
	}
	/*printf("\n방향 : %d\n", d);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", temp[i][j]);
		}
		printf("\n");
	}
	printf("\n");*/
	dfs(c + 1, temp);

}

int main()
{
	int arr[21][21];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0, arr);

	printf("%d", res);

	return 0;
}
