#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N,M;
int arr[100001];

int binarySearch(int num)
{

	int left, right, middle;

	left = 0;
	right = N - 1;
	

	while (1)
	{
		middle = (left + right) / 2;

		if (num == arr[middle])
			return 1;
		else if (num < arr[middle])
		{
			right = middle;
		}
		else
		{
			left = middle;
		}

		if (right - left == 1)
		{
			if (arr[right] == num || arr[left] == num)
				return 1;
			else
				return 0;
		}


	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(&arr[0], &arr[N]);

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int temp;
		scanf("%d", &temp);

		printf("%d\n", binarySearch(temp));

	}

	return 0;
}
