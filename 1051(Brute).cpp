#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N, M;
string str[51];
int nx, ny;
int d;
int res;
void brute(int x, int y)
{
	d = min(N - 1 - x, M - 1 - y);

	for (int i = d; i >= 1; i--)
	{
		nx = x + i;
		ny = y + i;

		if (str[x][y] == str[x][ny] && str[x][y] == str[nx][ny] && str[x][y] == str[nx][y])
		{
			res = max(res, i + 1);
		}

	}
	

}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			brute(i, j);
		}
	}
	if (res != 0)
		printf("%d", res*res);
	else
		printf("1");
	return 0;
}
