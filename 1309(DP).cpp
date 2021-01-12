#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[100001][3];

int dp(int n)
{
	
	for (int i = 2; i <= n; i++)
	{
		arr[i][0] = (arr[i-1][0] + arr[i - 1][1] + arr[i - 1][2]) % 9901;
		arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % 9901;
		arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % 9901;
	}

	return (arr[n][0] + arr[n][1] + arr[n][2]) % 9901;

}

int main()
{
	scanf("%d", &N);

	arr[1][0] = arr[1][1] = arr[1][2] = 1;

	printf("%d", dp(N));

	

	return 0;
}
