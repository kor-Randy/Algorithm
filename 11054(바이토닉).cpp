#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int res, temp, cnt;
int arr[1001];
int s[1001];
int d[1001];

void dp()
{
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				s[i] = max(s[i], s[j] + 1);
			}
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				d[i] = max(d[i], d[j] + 1);
			}
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
	for (int i = 0; i < N; i++)
	{
		d[i] = s[i] = 1;
	}
	dp();
	for (int i = 0; i < N; i++)
	{
		s[i] += d[i];
	}
	sort(&s[0], &s[N]);
	printf("%d", s[N - 1] - 1);
		

	return 0;
}
