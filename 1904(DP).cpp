#include<stdio.h>


using namespace std;

int temp[1000001];
int N;

int dp(int n)
{
	
	if (n == 1)
	{
		return 1;
	}
	else if (n == 2)
	{
		return 2;
	}
	else if (n == 3)
	{
		return 3;
	}
	else if (temp[n] != 0)
	{
		return temp[n];
	}
	else
	{
		return temp[n] = (dp(n - 1) + dp(n - 2))%15746;
	}

}

int main()
{
	scanf("%d", &N);
	printf("%d", dp(N));

	
	return 0;
}