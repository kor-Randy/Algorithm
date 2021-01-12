#include<stdio.h>
#include<iostream>
using namespace std;

int N;
int arr[46];

int brute(int n)
{
	int cut;
	for (int i = 1; i < 46; i++)
	{
		if (arr[i] > n)
			cut = i - 1;
	}

	for (int i = cut; i > 0; i--)
	{
		for (int j = cut; j > 0; j--)
		{
			for (int k = cut; k > 0; k--)
			{
				if (arr[i] + arr[j] + arr[k] == n)
					return 1;
			}
		}
	}
	return 0;
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i < 46; i++)
	{
		arr[i] = i*(i + 1) / 2;
	}

	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		printf("%d\n", brute(temp));
	}




	return 0;
}
