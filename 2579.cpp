#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int arr[301][3];
int score[301];

int dp(int n,int m)
{
	
	if (n == 1)
	{
		return arr[1][1] = score[1];
	}
	else if (n == 2 && m==1)
	{
		return arr[2][1] = score[1]+score[2];
	}
	else if (n == 2 && m == 2)
	{
		return arr[2][2] = score[2];
	}
	else if (arr[n][m] != 0)
	{
		return arr[n][m];
	}
	else
	{
		if (m == 1)
			return arr[n][m] =dp(n-1,2) + score[n];
		else
			return arr[n][m] = max(dp(n-2,1), dp(n-2,2)) + score[n];
		
	}
	

}

int main()
{
	scanf("%d", &N);
	
	for (int i = 1; i < N+1; i++)
	{
		scanf("%d", &score[i]);
	}
	
	int res = max(dp(N, 1), dp(N, 2));

	printf("%d", res);

	return 0;
}