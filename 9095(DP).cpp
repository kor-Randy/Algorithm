#include<stdio.h>
#include<iostream>

using namespace std;

int TK;
int res[12];

int dp(int n)
{
	if (n == 1)
	{
		return res[1]=1;
	}
	else if (n == 2)
		return res[2]=2;
	else if (n == 3)
		return res[3]=4;
	else if (res[n] != 0)
		return res[n];
	else
	{
		
		return res[n] = dp(n - 1) + dp(n - 2) + dp(n - 3);

	}

}

int main()
{
	scanf("%d", &TK);
	int temp;

	for (int i = 1; i <= TK; i++)
	{
	
		scanf("%d", &temp);
		dp(temp);
		printf("%d\n", res[temp]);
		
	}

	return 0;
}