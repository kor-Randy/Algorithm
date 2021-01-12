#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int n;
int arr[101];
int res;
int a, b,c;
int main()
{
	
	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 || b == 0 || c == 0)
			break;
		else
		{
			if (pow(a, 2) + pow(b, 2) == pow(c, 2))
				printf("right\n");
			else if (pow(a, 2) == pow(b, 2) + pow(c, 2))
				printf("right\n");
			else if (pow(a, 2) + pow(c, 2) == pow(b, 2))
				printf("right\n");
			else
				printf("wrong\n");
		}
	}

	return 0;
}
