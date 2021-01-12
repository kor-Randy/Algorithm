#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int tr[501][501];
int arr[501][501];
int N;
vector<int> vc;
int dp(int n,int m)
{
	if (n == 1)
	{
		return arr[1][1] = tr[1][1];
	}
	else if (arr[n][m] != 0)
	{
		return arr[n][m];
	}
	else
	{
		

			if (m == 1)
			{
				return arr[n][m] = dp(n - 1, m) + tr[n][m];
			}
			else if (m == n)
			{
				return arr[n][m] = dp(n - 1, m - 1) + tr[n][m];
			}
			else
			{
				return arr[n][m] = max(dp(n - 1, m-1), dp(n - 1, m)) + tr[n][m];
			}

		
	}
}

int main()
{

	scanf("%d", &N);

	
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < i+1; j++)
		{
			scanf("%d", &tr[i][j]);
		}

	}

	for (int i = 1; i < N + 1; i++)
	{
		vc.push_back(dp(N, i));
	}
	sort(vc.begin(), vc.end());
	printf("%d", vc[N-1]);
	
	return 0;
}