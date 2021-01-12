#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
char arr[11][11];
int res, cnt, temp;

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &arr[i][j]);
		}
	}

	return 0;
}
