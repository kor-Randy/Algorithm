#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int A, B, V;
int res;
int main()
{
	scanf("%d %d %d", &A, &B, &V);

	V = V - A;
	res++;
	int temp = A - B;
	
	if (V <= 0)
	{
		printf("%d", res);
		return 0;
	}

	if ((double)V / temp == V / temp)
	{
		res += V / temp;
	}
	else
	{
		res += V / temp + 1;
	}

	printf("%d", res);
	return 0;
}
