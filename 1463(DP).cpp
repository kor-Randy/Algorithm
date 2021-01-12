#include<stdio.h>
#include<algorithm>

using namespace std;

int arr[1000001];
int N;

int dp(int n)
{
	
	if (n == 1)
		return arr[1] = 0;
	else if (n == 2)
		return arr[2] = 1;
	else if (arr[n] != 0)
		return arr[n];
	else
	{
		if (n % 6 == 0)
		{
			return arr[n] = min(min(dp(n/2), dp(n/3)),dp(n-1)) + 1;
		}
		else if (n % 2 == 0)
		{
			return arr[n] = min(dp(n/2), dp(n-1)) + 1;
		}
		else if (n % 3 == 0)
		{
			return arr[n] = min(dp(n/3), dp(n-1)) + 1;
		}
		else
		{
			return arr[n] = dp(n-1) + 1;
		}
	}

}

int main()
{
	scanf("%d", &N);

	printf("%d",dp(N));

	return 0;
}