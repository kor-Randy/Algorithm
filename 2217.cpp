#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, w, k;

int arr[100001];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	sort(&arr[0], &arr[N]);
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		res = max(res, arr[i] * (N- i));

	}

	printf("%d", res);


	return 0;
}
