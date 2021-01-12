#include<stdio.h>
#include<iostream>
using namespace std;

int X;
int arr[65];
int cnt;
int simul()
{
	int sum;
	while (1)
	{
		sum = 0;

		for (int i = 0; i <= cnt; i++)
			sum += arr[i];
		
		if (sum == 0)
			sum = 64;

		if (sum > X)
		{
			int half = arr[cnt] / 2;
			if (sum - half >= X)
				arr[cnt] = half;
			else
			{
				arr[cnt] = arr[cnt + 1] = half;
				cnt++;
			}
		}
		
		if (sum == X)
			break;
		
	}
	return cnt;
}

int main()
{
	scanf("%d", &X);


	arr[1] = 64;
	cnt = 1;
	printf("%d", simul());

	return 0;
}