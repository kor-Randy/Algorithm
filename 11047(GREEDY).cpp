#include<stdio.h>
#include<iostream>

using namespace std;

int N, K;
int arr[11];
int res;

int greedy()
{
	int rest=K;
	
			for (int i = N - 1; i >= 0; i--)
			{
				while (1)
				{
					if (rest == 0)
						return res;
					else if (rest < arr[i])
						break;
					else
					{
						res++;
						rest -= arr[i];
					}
				}
			}
		

}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d", greedy());
	
	return 0;
}