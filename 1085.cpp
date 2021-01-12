#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int x, y, w, h;
int res;
int main()
{
	scanf("%d %d %d %d", &x, &y, &w, &h);

	res = 10000;

	res = min(res, x - 0);
	res = min(res, w - x);
	res = min(res, y-0);
	res = min(res, h-y);

	printf("%d", res);

	return 0;
}
