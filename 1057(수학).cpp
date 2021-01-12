#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int a, b;
int res;

int main()
{
	scanf("%d %d %d", &N, &a, &b);
	res = 1;
	while (1)
	{
		if (abs(a - b) == 1 && min(a,b)%2==1)
		{
			break;
		}
		else
		{

			if (a / 2 == (double)a / 2)
				a /= 2;
			else
				a = a / 2 + 1;

			if (b / 2 == (double)b / 2)
				b /= 2;
			else
				b = b / 2 + 1;

			res++;

		}


	}

	printf("%d", res);

	return 0;
}
