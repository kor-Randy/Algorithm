#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int C, N;
int arr[1001];
int a;
double res,temp;
int main()
{
	scanf("%d", &C);
	for (int i = 0; i < C; i++)
	{
		a = 0;
		temp = 0;
		scanf("%d", &N);
		
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[j]);
			temp += arr[j];
		}

		temp /= N;

		for (int j = 0; j < N; j++)
		{
			if (arr[j] > temp)
			{
				a++;
			}
		}

		printf("%.3lf%\n", (double)a*100 / N);

	}

	return 0;
}
