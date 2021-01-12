#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N;
string str[51];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int res, temp1,temp2, cnt;
int a, b;
char ch;

void check()
{
	
	for (int i = 0; i < N; i++)
	{
		temp1 = temp2 = 1;
		for (int j = 0; j < N - 1; j++)
		{
			if (str[i][j] == str[i][j + 1])
			{
				temp1++;
			}
			else
			{
				temp1 = 1;
			}

			if (str[j][i] == str[j + 1][i])
			{
				temp2++;
			}
			else
			{
				temp2 = 1;
			}

			a = max(a, temp1);
			b = max(b, temp2);

		}
	}
}

void brute(int x, int y)
{
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i];
		int ny = y + yy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		else
		{
			ch = str[x][y];
			str[x][y] = str[nx][ny];
			str[nx][ny] = ch;
			check();
			ch = str[x][y];
			str[x][y] = str[nx][ny];
			str[nx][ny] = ch;
		}
	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			brute(i, j);
		}
	}

	printf("%d", max(a, b));

	return 0;
}
