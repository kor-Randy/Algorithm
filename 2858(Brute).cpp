#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int L, W;
int R, B;

int main()
{
	scanf("%d %d", &R, &B);

	for (int i = 3; i <= sqrt(R + B); i++)
	{
		int j = (R + B) / i;

		if ((j - 2)*(i - 2) == B)
		{
			printf("%d %d", max(i, j), min(i, j));
			break;
		}

	}

	return 0;
}
