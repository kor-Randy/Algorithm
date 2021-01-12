#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a, b, c, d, e;
int main()
{
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

	if (a < 40)
		a = 40;
	if (b < 40)
		b = 40;
	if (c < 40)
		c = 40;
	if (d < 40)
		d = 40;
	if (e < 40)
		e = 40;

	printf("%d", (a + b + c + d + e) / 5);

	return 0;
}
