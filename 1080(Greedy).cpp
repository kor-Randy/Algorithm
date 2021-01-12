#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int a[51][51];
int b[51][51];
int arr[51][51];
int N, M, temp, res, cnt;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		string str = "";
		
		cin >> str;

		for (int j = 0; j < M; j++)
		{
			a[i][j] = str[j] - '0';
		}

	}

	for (int i = 0; i < N; i++)
	{
		string str = "";

		cin >> str;

		for (int j = 0; j < M; j++)
		{
			b[i][j] = str[j] - '0';
		}

	}

	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (a[i][j] != b[i][j] && (N < 3 || M < 3))
			{
				printf("-1");
				return 0;
			}
			else if (a[i][j] != b[i][j])
				arr[i][j] = 1;
		}
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i + 2 >= N || j + 2 >= M || arr[i][j]==0)
				continue;
			else
			{
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						arr[i + k][j + l] = (arr[i + k][j + l] + 1) % 2;
						
					}
				}
				res++;
			}

		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 1)
			{
				printf("-1");
				return 0;
			}
		}
	}
	printf("%d", res);

	return 0;
}
