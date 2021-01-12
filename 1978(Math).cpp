#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int res,cnt,temp;
void find()
{
	for (int i = 0; i < N; i++)
	{
		temp = 0;
		if (arr[i] == 1)
			temp = 1;
		else if (arr[i] == 2)
			res++;
		else
		{
			for (int j = 2; j < arr[i]; j++)
			{
				if (arr[i] % j == 0)
				{
					temp = 1;
					break;
				}
			}
			if (temp == 0)
				res++;
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int i= 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	find();
	printf("%d", res);
	return 0;
}
