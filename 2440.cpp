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
		for (int i = a-j+1; i > 0; i--)
		{

			
			
				printf("*");
			

		}
		printf("\n");
	}
	return 0;
}