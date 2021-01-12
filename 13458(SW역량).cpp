#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1000001];
int C, B;
long long res, temp, cnt;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d %d", &B, &C);

	
		for (int i = 0; i < N; i++)
		{
			arr[i] -= B;
			res++;
			if (arr[i] > 0)
			{
				if ((double)arr[i] / C != arr[i] / C)
				{
					res += arr[i] / C + 1;
				}
				else
				{
					res += arr[i] / C;
				}
			}

		}
	

	printf("%ld", res);



	return 0;
}
