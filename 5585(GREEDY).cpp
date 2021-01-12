#include<stdio.h>
#include<iostream>

using namespace std;

int N;
int arr[6];
int res;
int greedy()
{
	for (int i = 0; i < 6; i++)
	{
		while (1)
		{
			if (N < arr[i])
				break;
			else if (N == 0)
				break;
			else
			{
				N -= arr[i];
				res++;
			}
		}
	}
	return res;
}

int main()
{
	scanf("%d", &N);

	N = 1000 - N;

	arr[0] = 500;
	arr[1] = 100;
	arr[2] = 50;
	arr[3] = 10;
	arr[4] = 5;
	arr[5] = 1;

	printf("%d", greedy());

	return 0;
}