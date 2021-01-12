#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	long long res=1;

	if (n == 0)
		printf("1");
	else
	{
		for (int i = 1; i <= n; i++)
			res *= i;
		printf("%lld", res);
	}
	return 0;
}
