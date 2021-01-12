#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int N;
int arr[1001];
int res;
int sum, temp;
int greedy()
{

	for (int i = 0; i < N; i++)
	{
		sum += arr[i];

		temp += arr[i] * ((N - 1) - i);

	}

	return sum + temp;


}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(&arr[0], &arr[N]);

	printf("%d", greedy());

	return 0;
}