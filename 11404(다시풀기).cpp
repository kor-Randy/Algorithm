#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,M;
vector<pair<int, int>> vc[101];
int arr[101][101];

int main()
{

	

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = 1000000000;
		}
	}

	for (int i = 1; i <= M; i++)
	{
		int a, b,c;
		scanf("%d %d %d", &a , &b , &c);

		arr[a][b] = min(arr[a][b], c);
	}

	


	for (int i = 1; i <= N; i++)
	{//middle
		for (int j = 1; j <= N; j++)
		{//start
			if (arr[j][i] == 0)
				continue;
			for (int k = 1; k <= N; k++)
			{//end
				

				if (arr[i][k] == 0 || j==k)
					continue;
				else
				{
					if (arr[j][k] == 0)
						arr[j][k] = arr[j][i] + arr[i][k];
					else
						arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
				}

			}
		}
	}

	for (int i = 1; i <= N; i++)
	{//middle
		for (int j = 1; j <= N; j++)
		{//start
			if (arr[i][j] == 1000000000)
				printf("0 ");
			else
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
