#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[1000001];
long long res, temp, cnt;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int left = 0;
	int right = 1000000000;
	int middle = (left+right)/2;

	sort(&arr[0], &arr[N]);

	while (1)
	{
		if (middle == left)
			break;
		
		//printf("middle°ª : %d\n", arr[middle]);
		for (int i = 0; i < N; i++)
		{
			if(arr[i]>middle)
				temp += arr[i] - middle;
		}

		if (temp > M)
		{
			left = middle;
			middle = (left+right) / 2;
		}
		else if (temp == M)
		{
			break;
		}
		else
		{
			right = middle;
			middle = (left + right) / 2;
		}
		temp = 0;
	
	}

	printf("%d", middle);



	return 0;
}
