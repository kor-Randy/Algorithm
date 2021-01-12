#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int a, b;

int main()
{
	scanf("%d %d", &a, &b);

	printf("%.10lf", (double)a / (double)b);

	return 0;
}
