#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[21][21];
int mission[1001];
int dice[7];
int temp[7];
int N, M, K;
int x, y ;

int main()
{
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < K; i++)
	{
		scanf("%d", &mission[i]);
	}

	for (int i = 0; i < K; i++)
	{
		for (int j = 1; j < 7; j++)
			temp[j] = dice[j];

		if (mission[i] == 1)
		{
			
			

			int nx = x;
			int ny = y + 1;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			dice[1] = temp[3];
			dice[3] = temp[6];
			dice[6] = temp[4];
			dice[4] = temp[1];
			if (arr[nx][ny] == 0)
			{
				arr[nx][ny] = dice[1];
				printf("%d\n", dice[6]);
			}
			else
			{
				dice[1] = arr[nx][ny];
				arr[nx][ny] = 0;
				printf("%d\n", dice[6]);
			}
			y++;
		}
		else if (mission[i] == 2)
		{
		

			int nx = x;
			int ny = y - 1;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			dice[1] = temp[4];
			dice[4] = temp[6];
			dice[6] = temp[3];
			dice[3] = temp[1];
			if (arr[nx][ny] == 0)
			{
				arr[nx][ny] = dice[1];
				printf("%d\n", dice[6]);
			}
			else
			{
				dice[1] = arr[nx][ny];
				arr[nx][ny] = 0;
				printf("%d\n", dice[6]);
			}
			y--;

		}
		else if (mission[i] == 3)
		{
			

			int nx = x - 1;
			int ny = y;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			dice[1] = temp[2];
			dice[2] = temp[6];
			dice[6] = temp[5];
			dice[5] = temp[1];
			if (arr[nx][ny] == 0)
			{
				arr[nx][ny] = dice[1];
				printf("%d\n", dice[6]);
			}
			else
			{
				dice[1] = arr[nx][ny];
				arr[nx][ny] = 0;
				printf("%d\n", dice[6]);
			}
			x--;
		}
		else
		{
			

			int nx = x + 1;
			int ny = y;
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			dice[1] = temp[5];
			dice[5] = temp[6];
			dice[6] = temp[2];
			dice[2] = temp[1];
			if (arr[nx][ny] == 0)
			{
				arr[nx][ny] = dice[1];
				printf("%d\n", dice[6]);
			}
			else
			{
				dice[1] = arr[nx][ny];
				arr[nx][ny] = 0;
				printf("%d\n", dice[6]);
			}
			x++;
		}
	}



	return 0;
}
