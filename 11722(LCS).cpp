#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int check[1001];
vector<int> vc;
int res, temp;


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < N; i++)
	{
		check[i] = 1;
		for (int j = 0; j < i; j++)
		{

			if (arr[i] > arr[j])
			{
				if (check[i] < check[j] + 1)
				{
					check[i] = check[j] + 1;
				}
			}
		}
	}

	sort(&check[0], &check[N]);


	

	printf("%d", check[N-1]);

	return 0;
}
