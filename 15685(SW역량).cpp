#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int arr[101][101];
int x, y, d, g;
int res, cnt, temp;
vector<pair<int, int>> vc;
void simul()
{
	cnt = 0;
	if (d == 0)
	{
		vc.push_back({ x + 1,y });
	}
	else if (d == 1)
	{
		vc.push_back({ x,y - 1 });
	}
	else if (d == 2)
	{
		vc.push_back({ x - 1,y });
	}
	else
	{
		vc.push_back({ x,y + 1 });
	}

	while (1)
	{
		if (cnt == g) {
			//printf("vcÀÇ °¹¼ö : %d\n", vc.size());
			break;
		}
		else
		{
			//printf("vcÀÇ °¹¼ö : %d\n", vc.size());
			int lx = vc[vc.size() - 1].first;
			int ly = vc[vc.size() - 1].second;
			int ss = vc.size();
			for (int i = ss-2; i >=0; i--)
			{
				int x = vc[i].first;
				int y = vc[i].second;
				//printf("x : %d, y :  %d\n", x, y);
				if (x < 0 || x>100 || y < 0 || y>100)
					continue;
				else
				{
					vc.push_back({ lx - (y - ly),ly + (x - lx) });
				}
			}
			cnt++;
		}
	}

	for (int i = 0; i < vc.size(); i++)
	{
		//printf("%d, %d\n", vc[i].first, vc[i].second);
		if (vc[i].first < 0 || vc[i].first>100 || vc[i].second < 0 || vc[i].second>100)
			continue;
		else
			arr[vc[i].first][vc[i].second] = 1;
	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d %d", &x, &y, &d, &g);
		vc.push_back({ x,y });
		simul();
		vc.clear();
	}

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			if (i + 1 > 100 || j + 1 > 100 || arr[i][j]==0)
				continue;
			else
			{
				if (arr[i][j] == 1 && arr[i + 1][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j + 1] == 1)
					res++;
			}

		}
	}

	printf("%d", res);


	return 0;
}
