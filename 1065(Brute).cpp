#include<stdio.h>
#include<iostream>

using namespace std;

int N;
int res;
int arr[4];
int brute()
{
	for (int i = 1; i <= N; i++)
	{
		if (i < 100)
			res++;
		else if (i == 1000)
			break;
		else
		{
			
				arr[1] = i % 10;
				arr[2] = (i/10) % 10;
				arr[3] = (i / 100);

				if (arr[3] - arr[2] == arr[2] - arr[1])
					res++;

			
		}
	}

	return res;
}

int main()
{
	scanf("%d", &N);

	printf("%d", brute());

	return 0;
}