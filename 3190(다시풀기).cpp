#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;

int N,K,L;
deque<pair<int, int>> dq;
vector<pair<int, char>> rt;
int arr[101][101];
int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };
int res, temp, cnt, d;
int time, index;
//0 : ºóÄ­ , 1 : »ç°ú , 2 : ¹ì
void simul()
{
	dq.push_back({ 0,0 });
	arr[0][0] = 2;
	while (1)
	{
		int x = dq.front().first;
		int y = dq.front().second;

		int nx = x + xx[d];
		int ny = y + yy[d];


		time++;

		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
		{
			//º®¿¡ ´êÀ½
			break;
		}
		else if (arr[nx][ny] == 2)
		{
			//¸ö¿¡ ´êÀ½
			break;
		}
		else if(arr[nx][ny]==1)
		{
			//»ç°ú¸¦ ¸ÔÀ½
			dq.push_front({ nx,ny });
			arr[nx][ny] = 2;
		}
		else
		{
			//»ç°ú¸¦ ¸ÔÁö ¸øÇÔ
			arr[dq.back().first][dq.back().second] = 0;
			dq.pop_back();

			dq.push_front({ nx,ny });
			arr[nx][ny] = 2;
		}

		if (index < L)
		{
			if (time == rt[index].first)
			{
				if (rt[index].second == 'D')
				{
					d = (d + 1) % 4;
				}
				else
				{
					if (d == 0)
						d = 3;
					else
						d -= 1;
				}
				index++;
			}
		}



	}


}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a-1][b-1] = 1;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		rt.push_back({ a,b });
	}

	simul();
	printf("%d", time);

	return 0;
}
