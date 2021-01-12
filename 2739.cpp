#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	
	int a;
	
	scanf("%d",&a);
	
	for (int j = 0; j < a; j++)
	{
		for (int i = 1; i < a + 1; i++)
		{

			printf("*");

		}
		printf("\n");
	}
	return 0;
}