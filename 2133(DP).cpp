#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[31];
int dp(int n)
{
	//printf("n : %d\n", n);
	if (n % 2 == 1)
		return arr[n] = 0;
	else if (n == 2)
	{
		return arr[n] = 3;
	}
	else if (n == 4)
	{
		return arr[n] = 11;
	}
	else if (arr[n] != 0)
		return arr[n];
	else
	{
		int temp = 0;
		for (int i = n-2; i >= 2; i -= 2)
		{
			if (i == n-2)
				temp += dp(i) * 3;
			else
				temp += dp(i) * 2;
		}
		return arr[n] = temp + 2;


	}

}

int main()
{
	scanf("%d", &N);
	printf("%d", dp(N));
	return 0;
}
