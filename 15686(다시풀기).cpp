#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int N, M;
int arr[51][51];
int d[51][51];
int res, temp, cnt;
vector<pair<int, int>> chi;
vector<pair<int, int>> home;
vector<pair<int, int>> vc;
void com(int c,int index)
{
	if (c == M)
	{
		for (int i = 0; i < home.size(); i++)
		{
			d[home[i].first][home[i].second] = 1000000;
		}
		temp = 0;
		for (int i = 0; i < home.size(); i++)
		{
			for (int j = 0; j < vc.size(); j++)
			{
				d[home[i].first][home[i].second] = 
					min(d[home[i].first][home[i].second], 
						abs(home[i].first - vc[j].first) + abs(home[i].second - vc[j].second));
			}
			temp += d[home[i].first][home[i].second];
		}

		
		res = min(res, temp);
		return;
	}


	for (int i = index; i < chi.size(); i++)
	{
		vc.push_back(chi[i]);
		com(c + 1,i+1);
		vc.pop_back();
	}

}

int main()
{
	scanf("%d %d", &N, &M);
	res = 1000000;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			d[i][j] = 1000000;
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1)
				home.push_back({ i,j });
			else if (arr[i][j] == 2)
				chi.push_back({ i,j });
		}

	com(0,0);

	printf("%d", res);

	return 0;
}
