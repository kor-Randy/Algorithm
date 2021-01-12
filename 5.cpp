#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	short a;

	short **b;

	scanf("%d", &a);




	for (int i = 0; i < (a / 5) + 1; i++)
	{

		for (int j = 0; j < (a / 3 + 1); j++)
		{

			b[i][j] = 5 * i + 3 * j;

			cout << b[i][j] << endl;

		}

	}





	return 0;
}