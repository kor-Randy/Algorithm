#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int arr[500001];

int find(int num)
{

	int l = 0;
	int r = N - 1;
	while (1)
	{

		int m = (l + r) / 2;
		if (arr[l] == num || arr[r] == num)
			return 1;
		else if (r - l == 1)
		{
			return 0;
		}
		else
		{
			if (arr[m] > num)
			{
				r = m;
			}
			else
			{
				l = m;
			}
		}

	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(&arr[0], &arr[N]);

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int a;
		scanf("%d", &a);
		printf("%d ", find(a));


	}
	return 0;
}
