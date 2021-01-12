#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int u[1001];

void lcs(int n)
{
	u[n] = 1;
	for (int i = 0; i < n; i++)
	{
		if (arr[n] > arr[i])
			u[n] = max(u[n], u[i] + 1);
	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < N; i++)
		lcs(i);

	sort(&u[0], &u[N]);

	printf("%d", u[N - 1]);


	return 0;
}
