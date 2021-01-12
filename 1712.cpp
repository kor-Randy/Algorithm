#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

unsigned long long A, B, C;
long long res, temp;
int main()
{
	scanf("%llu %llu %llu", &A, &B, &C);
	
	if (C>B)
		res = (A / (C - B)) + 1;
	else
		res = -1;

	printf("%ld", res);

	return 0;
}
