#include<stdio.h>
#include<vector>

using namespace std;

unsigned long long arr[101];
int TK,N;

unsigned long long dp(int n)
{
	if (n == 1 || n == 2 || n==3)
	{
		arr[1] = arr[2] = arr[3] = 1;
		return 1;
	}
	else if (n == 4 || n == 5)
	{
		arr[4] = arr[5] = 2;
		return 2;
	}
	else if (arr[n] != 0)
	{
		return arr[n];
	}
	else
	{
		return arr[n] = dp(n - 1) + dp(n - 5);
	}
}

int main()
{
	vector<unsigned long long> vc;
	scanf("%d", &TK);
	for (int i = 0; i < TK; i++)
	{
		scanf("%d", &N);

		vc.push_back(dp(N));
	}
	for (int i = 0; i < vc.size(); i++)
	{
		printf("%llu\n", vc[i]);
	}
	return 0;
}