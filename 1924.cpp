#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{

	int x;
	int count=0;
	scanf("%d", &x);

	for (int i = 1; i < x+1; i++)
	{
		
		count += i;
	}
	
	printf("%d", count);


	return 0;
}