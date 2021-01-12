#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int v[6] = { 1000,5,5,5,5,5 };
int arr[11][11];
int visit[11][11];
int d[11][11];//(x,y)칸에 (1,2,3,4,5)짜리 색종이를 놓았을 때의 값중에 최소값

int res;
int ss, num;

void dfs(int x, int y)
{
	//printf("x : %d , y : %d , arr[x][y] : %d\n", x, y, arr[x][y]);
	if (y == 10)
	{
		dfs(x + 1, 0);
		return;
	}

	if (x == 10)
	{

		int cnt = 0;
		for (int i = 1; i <= 5; i++)
		{
			cnt += v[i];
			//	printf("ss : %d,v[ss] : %d\n", i, v[i]);
		}
		//printf("\n\n\n");

		cnt = 25 - cnt;
		res = min(res, cnt);

		return;
	}

	if (arr[x][y] == 0)
	{
		if (y == 9)
			dfs(x + 1, 0);
		else
			dfs(x, y + 1);
		return;
	}
	else
	{

		for (int ss = 5; ss >= 1; ss--)
		{
			int t = 0;
			//printf("ss : %d\n", ss);
			for (int i = 0; i < ss; i++)
			{
				for (int j = 0; j < ss; j++)
				{
					int nx = x + i;
					int ny = y + j;
					if (nx >= 10 || ny >= 10 || arr[nx][ny] == 0)
					{
						t = 1;
						break;
					}
				}
				if (t == 1)
					break;
			}
			if (t == 0)
			{//1,2,3,4,5짜리 썼음
				if (v[ss] == 0)//ss를 다 사용했으면
					continue;

				for (int i = 0; i < ss; i++)
				{
					for (int j = 0; j < ss; j++)
					{
						arr[x + i][y + j] = 0;

					}
				}
				v[ss]--;
				num -= ss*ss;
				//printf("ss : %d짜리 사용\n", ss);


				dfs(x, y + ss);

				for (int i = 0; i < ss; i++)
				{
					for (int j = 0; j < ss; j++)
					{
						arr[x + i][y + j] = 1;

					}
				}
				v[ss]++;
				num += ss*ss;

			}


		}
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				num++;

		}
	res = 10000000;

	dfs(0, 0);

	if (res >= 26)
		printf("-1");
	else
		printf("%d", res);



	return 0;
}
