#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int N;
int arr[126][126];
int v[126][126];
int aa[4] = { -1,0,1,0 };
int bb[4] = { 0,-1,0,1 };
void dijk()
{
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -arr[0][0],{0,0} });
	v[0][0] = arr[0][0];
	while (1)
	{
		int cost = -pq.top().first;
		int now_row = pq.top().second.first;
		int now_col = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++)
		{
			if (v[now_row + aa[i]][now_col + bb[i]] != 1000000)
			{
				continue;
			}
			else 
			{
				if (now_row + aa[i] >= 0 && now_col + bb[i] >= 0 && now_row + aa[i] <= N - 1 && now_col + bb[i] <= N - 1)
				{
					v[now_row + aa[i]][now_col + bb[i]] = min(v[now_row + aa[i]][now_col + bb[i]], cost + arr[now_row + aa[i]][now_col + bb[i]]);
					pq.push({ -v[now_row + aa[i]][now_col + bb[i]],{now_row + aa[i],now_col + bb[i]} });
				}
				else
				{
					continue;
				}

			}
		}

		if (pq.empty())
			break;

	}
	

}

int main()
{
	int cnt = 1;
	while (1)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		else
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					scanf("%d", &arr[i][j]);
				}
			}


			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					
					v[i][j] = 1000000;
				}
			}
			dijk();

			

			printf("Problem %d: %d\n", cnt,v[N - 1][N - 1]);
			cnt++;


		}



	}
	return 0;
}
