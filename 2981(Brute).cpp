#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int N, M;
vector<int> vc;
int arr[101];

int GCD(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}

	return GCD(b, a % b);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(&arr[0], &arr[N]);

	int m = arr[N - 1] - arr[N - 2];

	for (int i = N-2; i >0; i--)
	{
		m = GCD(m, arr[i]-arr[i-1]);

		

	}

	for (int i = 2; i <= sqrt(m); i++)
	{
		if (m%i == 0)
		{
			vc.push_back(i);
			vc.push_back(m / i);
		}
	}
	vc.push_back(m);
	sort(vc.begin(), vc.end());

	vc.erase(unique(vc.begin(), vc.end()),vc.end());

	for (int i = 0; i < vc.size(); i++)
		printf("%d ", vc[i]);




	return 0;
}
