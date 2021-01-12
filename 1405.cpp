#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;

double per[4];
int visit[31][31];
double res;
int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
int a, b;
void dfs(int x, int y,int c,double p)
{
	if (c == N)
	{
		res += p;
		return;
	}
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i];
		int ny = y + yy[i];
		if (visit[nx][ny] == 1)
			continue;
		visit[nx][ny] = 1;
		dfs(nx, ny, c + 1, p*per[i]);
		visit[nx][ny] = 0;

	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < 4; i++)
	{
		int a;
		scanf("%d", &a);
		per[i] = (double)a / 100;
	}
	visit[15][15] = 1;
	dfs(15, 15,0,1.0);
	printf("%.9g", res);

	return 0;
}
