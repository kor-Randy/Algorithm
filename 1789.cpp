#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

unsigned long long S;

unsigned long long res, cnt, temp;
int main()
{
	scanf("%llu", &S);
	temp = 1;
	while (1)
	{
		if (S >= temp)
		{
			S -= temp;
			temp++;
			cnt++;
		}
		else
		{
			printf("%llu", cnt);
			break;
		}
	}

	return 0;
}
