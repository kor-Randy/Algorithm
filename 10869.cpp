#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	short a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	cout << (a + b)%c << endl << (a%c+b%c)%c << endl << (a*b)%c << endl << (a%c * b%c)%c;

	return 0;
}