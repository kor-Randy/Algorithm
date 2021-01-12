#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int N;
string s[101];
char arr[101][101];
int check[101][101];//Àû 1 ³ì 2 Ã» 3 -> Àû³ì»ö¾à =  1, 1, 3
int check1[101][101];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int res, res1;
int dfs(int x, int y)
{
	if (check[x][y] != 0)
		return 2;

	char c = arr[x][y];

	
	if (c == 'R')
		check[x][y] = 1;
	else if (c == 'G')
		check[x][y] = 2;
	else
		check[x][y] = 3;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i];
		int ny = y + yy[i];
		int nc = arr[nx][ny];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		else
		{
			if (c != nc)
				continue;
			else
				dfs(nx, ny);
		}

	}
	return 1;

}

int dfs1(int x, int y)
{
	if (check1[x][y] != 0)
		return 2;

	char c = arr[x][y];
	

	if (c == 'R' || c == 'G')
		check1[x][y] = 1;
	else
		check1[x][y] = 3;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i];
		int ny = y + yy[i];
		int nc = arr[nx][ny];

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		else if (c != nc)
		{
			if ((c == 'R'&&nc == 'G') || (c == 'G'&&nc == 'R'))
				dfs1(nx, ny);
			else
				continue;
		}
		else
		{
			dfs1(nx, ny);


		}

	}
	return 1;

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", &arr[i]);
	}

	


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			if (dfs(i, j) == 1)
				res++;
		}
	}
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			if (dfs1(i, j) == 1)
				res1++;
		}
	}

	printf("%d %d", res, res1);


	return 0;
}
