#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

//(3,3)에 입력으로 가로 사다리(1)가 주어지면
//(3,2)에는 3이 들어가고 (3,4)에는 2가 들어간다 
//1 : 오른쪽으로 이동 ,  2 : 왼쪽으로 이동 , 3 : 사다리를 놓지 못함
//하지만 (3,1)에 가로 사다리(1)를 놓게 되면
//(3,2)는 왼쪽으로 이동하는 2값이 들어가야 하는데 (3,3)때문에 3이 이미 들어가있음.
//따라서 (3,2)에 32를 넣어 dfs를 수행하고 되돌아 갈때 3으로 돌아감
//(3,5)에 가로 사다리(1)를 추가하는 경우에도 마찬가지로 (3,4)에 3을 넣어야하지만 이미 2가 존재
//따라서 (3,4)에 23을 넣어 dfs를 수행하고 되돌아 갈때 2로 돌아감
//또한, 23 32 2 모두 왼쪽으로 이동해야 하기때문에 수행할 때에는 2와 마찬가지로 본다.

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
			//하나라도 틀리다
			flag = false;
			break;
		}
	}

	if (flag == false)
	{
		//dfs를 해야함
		
		for (int i = ii; i <= H; i++)
		{
			for (int j = 1; j < N; j++)
			{				
				//printf(" %d , %d 에 놓을수 있나?\n", i, j);

				if (arr[i][j] == 0)
				{
					//printf("i : %d , j : %d arr[i][j] : %d 에 사다리 놓음\n", i, j,arr[i][j]);

					
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
		arr[a][b] = 1;//가로선의 양 옆에꺼는 추가 불가능
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
