#include<stdio.h>
#include<iostream>
using namespace std;

pair<int, int> one[6] = { {500,1},{300,2},{200,3},{50,4},{30,5},{10,6} };
pair<int, int> two[5] = { {512,1},{256,2},{128,4},{64,8},{32,16} };
int res;
int TK;
int a, b;

int aa(int n)
{
	if(n>=22 || n == 0)
	{
		return 0;
	}
	else
	{
		if (n < 2)
			return 5000000;
		else if (n < 4)
			return 3000000;
		else if (n < 7)
			return 2000000;
		else if (n < 11)
			return 500000;
		else if (n < 16)
			return 300000;
		else
			return 100000;
	}
}
int bb(int n)
{
	if (n >= 32 || n == 0)
	{
		return 0;
	}
	else
	{
		if (n < 2)
			return 5120000;
		else if (n < 4)
			return 2560000;
		else if (n < 8)
			return 1280000;
		else if (n < 16)
			return 640000;
		else
			return 320000;
	}
}

int main()
{
	scanf("%d", &TK);

	for (int i = 0; i < TK; i++)
	{
		scanf("%d %d", &a, &b);

		printf("%d\n", aa(a) + bb(b));

	}


	return 0;
}
