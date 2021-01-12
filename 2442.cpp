#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int N;
int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < (N - 1 - i); j++)
			printf(" ");
		for (int j = 0; j < 2 * i + 1; j++)
			printf("*");

		printf("\n");
	}

	return 0;
}
