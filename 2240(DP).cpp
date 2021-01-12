#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int T, W;
int arr[1001];
int visit[1001][3][31];
vector<int> vc;
void dp()
{
	for (int i = 1; i <= T; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if ((i == 0 && j == 0)|| j>i)
				continue;
			if (arr[i] == 0)
			{
				if (j == 0)
				{
					visit[i][0][j] = visit[i-1][0][j] + 1;
					
				}
				else
				{
					visit[i][0][j] = max(visit[i - 1][0][j], visit[i - 1][1][j - 1]) + 1;
					visit[i][1][j] = max(visit[i - 1][0][j - 1], visit[i - 1][1][j]);
				}

			}
			else
			{
				if (j == 0)
				{
					continue;
				}
				else
				{
					visit[i][1][j] = max(visit[i - 1][1][j], visit[i - 1][0][j - 1]) + 1;
					visit[i][0][j] = max(visit[i - 1][1][j - 1], visit[i - 1][0][j]);
				}
			}
			

		}


	}

}

int main()
{
	scanf("%d %d", &T, &W);
	for (int i = 1; i <= T; i++)
	{
		int a;
		scanf("%d", &a);
		arr[i] = a - 1;
	}

	dp();

	for (int i = 0; i <= W ; i++)
	{
		vc.push_back(visit[T][0][i]);
		vc.push_back(visit[T][1][i]);
	}
	sort(vc.begin(), vc.end());
	printf("%d", vc[vc.size() - 1]);

	return 0;
}
