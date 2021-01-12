#include<stdio.h>
#include<iostream>
using namespace std;

int N;
int arr[1001];
int check[1001][10];
int temp1, temp2;

int dp(int n)
{
	if (n == 1)
	{
		for (int i = 0; i < 10; i++)
		{
			check[1][i] = 1;
		}
		return arr[1] = 10;

	}
	else if (arr[n] != 0)
		return arr[n]%10007;
	else
	{
		temp1 = dp(n - 1);
		int res=0;
		//printf("n = %d \n", n);
		for (int i = 0; i < 10; i++)
		{
			if (i == 0)
			{
				check[n][0] = temp1;
				res += temp1;
				res = res % 10007;
				check[n][0] %= 10007;
				//printf("check[n][0] = %d", check[n][0]);
				continue;
			}

			check[n][i] = (check[n][i-1]) - (check[n - 1][i-1]);
			if (check[n][i] < 0)
				check[n][i] += 10007;
			//printf("check[n][i] : %d , check[n][i-1] : %d , check[n-1][i-1] : %d\n", check[n][i], check[n][i - 1], check[n - 1][i - 1]);

			check[n][i] %= 10007;
			
			}
		
		
		for (int i = 0; i < 10; i++)
			arr[n] += check[n][i];
		arr[n] %= 10007;
		//printf("arr[%d] = %d\n", n, arr[n]);
		return arr[n];
	}
}

int main()
{
	scanf("%d", &N);

	printf("%d", dp(N)%10007);

	return 0;
}
