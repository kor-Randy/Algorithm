#include<stdio.h>
#include <queue>
#include<algorithm>

using namespace std;

int N, M;

int arr[1001][1001];
int day[1001][1001];
vector<int> vc;
queue<pair<int, int>> check;

int ans;




int search()
{

	
	while (1)
	{
		int x = check.front().first;
		int y = check.front().second;
		check.pop();
		
		int count = 1;
		
			
		if(x>0)
		{
				if (arr[x - 1][y] == 0&& day[x-1][y]==0)
				{
					
						day[x - 1][y] = day[x][y]+1;
					
					check.push(make_pair(x - 1, y));
				}
		}
		if(x<M-1)
		{
				if (arr[x + 1][y] == 0&& day[x + 1][y] == 0)
				{
					
						day[x + 1][y] = day[x][y] + 1;
					
					check.push(make_pair(x + 1, y));
				}
		}
		if(y>0)
		{
				if (arr[x][y - 1] == 0&& day[x][y - 1] == 0)
				{
					
						day[x][y - 1] = day[x][y] + 1;
					
					check.push(make_pair(x, y - 1));
				}
		}
		if(y<N-1)
		{
				if (arr[x][y + 1] == 0 && y<N - 1 && day[x][y + 1] == 0)
				{
					
						day[x][y + 1] = day[x][y] + 1;
					
					check.push(make_pair(x, y + 1));
				}
		}
				
				if (check.empty())
				{
					break;
				}

		


	}


	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			vc.push_back(day[i][j]);
		}
	}

	sort(vc.begin(), vc.end());
	

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (day[i][j] == 0 && arr[i][j]==0)
			{
				ans= -1;
				return ans;
			}
			else
			{
				ans = vc.back();
			}
		}
	}


	return ans;
	

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
			{
				check.push(make_pair(i, j));
			}
		}
	}

	search();

	printf("%d",ans);
	




	return 0;
}