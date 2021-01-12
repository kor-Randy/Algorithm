#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int TK, N,M;
int check[1001];
int arr[1001][1001];


int main()
{
	scanf("%d", &TK);



	for (int i = 0; i < TK; i++)
	{ 
		scanf("%d %d", &N, &M);
		for (int j = 0; j < M; j++)
		{
			int temp1,temp2;
			scanf("%d %d", &temp1, &temp2);
		}

		printf("%d\n", N - 1);
	}

	return 0;
}
