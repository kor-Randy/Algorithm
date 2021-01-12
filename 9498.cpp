#include<stdio.h>
#include<iostream>
using namespace std;

int N;

int main()
{
	scanf("%d", &N);

	if (N <= 100 && N >= 90)
		printf("A");
	else if (N <= 89 && N >= 80)
		printf("B");
	else if (N <= 79 && N >= 70)
		printf("C");
	else if (N <= 69 && N >= 60)
		printf("D");
	else
		printf("F");
	return 0;
}
