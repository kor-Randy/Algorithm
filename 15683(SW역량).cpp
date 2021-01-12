#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int arr[9][9];
int res, temp, cnt;
vector<pair<int, int>> vc;
int xx[4] = { -1,0,1,0 };
int yy[4] = { 0,1,0,-1 };

void back(int x, int y, int d)
{

	//printf("back -- x : %d , y : %d , d : %d\n", x, y, d);

	int nx = x;
	int ny = y;
	while (1)
	{
		nx = nx + xx[d];
		ny = ny + yy[d];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 6)
		{
			return;
		}
		else
		{
			if (arr[nx][ny] == 10)//내가 봤던 공간이고 다른 카메라가 아니면
				arr[nx][ny] = 0;
			else if (arr[nx][ny] > 10)
				arr[nx][ny]--;
		}

	}
}

void go(int x, int y, int d)
{
	//printf("go -- x : %d , y : %d , d : %d\n", x, y, d);
	int nx = x;
	int ny = y;
	while (1)
	{
		nx = nx + xx[d];
		ny = ny + yy[d];
		//printf("go -- nx : %d , ny : %d \n", nx, ny);
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || arr[nx][ny] == 6)
		{
			return;
		}
		else
		{
			if (arr[nx][ny] == 0)//다른 카메라가 아니면
				arr[nx][ny] = 10;
			else if (arr[nx][ny] >= 10)
				arr[nx][ny]++;
		}

	}
}

int check()
{
	int temp = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			//printf("%d ", arr[i][j]);
			if (arr[i][j] == 0)
				temp++;
		}
		//printf("\n");
	}
	return temp;
}

void dfs(int index)
{
	if (index == vc.size())
	{

		res = min(res, check());
		//printf("res : %d\n", res);
		return;
	}

	
		int x = vc[index].first;
		int y = vc[index].second;
		int num = arr[x][y];

		if (num == 1)
		{
			for (int j = 0; j < 4; j++)
			{
				go(x,y,j);
				dfs(index + 1);
				back(x, y, j);
			}
		}
		else if (num == 2)
		{
			for (int j = 0; j < 2; j++)
			{
				go(x, y, j);
				go(x, y, (j + 2)%4);
				dfs(index + 1);
				back(x, y, j);
				back(x, y, (j + 2) % 4);
			}
		}
		else if (num == 3)
		{
			for (int j = 0; j < 4; j++)
			{
				go(x, y, j);
				go(x, y, (j + 1)%4);
				dfs(index + 1);
				back(x, y, j);
				back(x, y, (j + 1) % 4);
			}
		}
		else if (num == 4)
		{
			for (int j = 0; j < 4; j++)
			{
				go(x, y, j);
				go(x, y, (j + 1) % 4);
				go(x, y, (j + 3) % 4);
				dfs(index + 1);
				back(x, y, j);
				back(x, y, (j + 1) % 4);
				back(x, y, (j + 3) % 4);
			}
		}
		else
		{
			go(x, y, 0);
			go(x, y, 1);
			go(x, y, 2);
			go(x, y, 3);
			dfs(index + 1);
			back(x, y, 0);
			back(x, y, 1);
			back(x, y, 2);
			back(x, y, 3);
		}



	

}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] != 0 && arr[i][j] != 6)
			{
				vc.push_back({ i,j });
			}
		}
	}
	res = 100;
	dfs(0);

	printf("%d", res);

	return 0;
}
