#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{

	int a;
	scanf("%d", &a);

	for (int j = 1; j < a+1; j++)
	{
		for (int i = a; i > 0; i--)
		{

			if (i > j)
			{
				printf(" ");
			}
			if (i <= j)
			{
				printf("*");
			}

		}
		printf("\n");
	}
	return 0;
}