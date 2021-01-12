#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, K, L;
int arr[102][102];
vector<pair<int, char>> vc;
int temp, res, cnt, len;
int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };
int index, ti;
int hv, tv;
void simul()
{
	
	pair<int, int> head;
	head = { 1,1 };
	pair<int, int> tail;
	tail = { 1,1 };
	index = 0;
	ti = 0;
	len = 1;
	arr[head.first][head.second] = 1;
	while (1)
	{
		
		int nx = head.first + xx[index];
		int ny = head.second + yy[index];

		if (nx <= 0 || nx > N || ny <= 0 || ny > N || arr[nx][ny]==1)
		{
			//printf("게임 끝\n");
			cnt++;
			break;
		}
		else
		{
			if (arr[nx][ny] == 2)
			{
				//사과o
				head = { nx,ny };
				arr[nx][ny] = 1;
				len++;
			}
			else
			{
				//사과x
				head = { nx,ny };
				arr[tail.first][tail.second] = 0;
				tail = { tail.first + xx[ti],tail.second + yy[ti] };
				arr[nx][ny] = 1;
			}
			
			cnt++;
			/*printf("%d초\n", cnt);
			printf("nx : %d , ny : %d\n", nx, ny);
			printf("tail x : %d , y : %d\n", tail.first, tail.second);*/
		}

		if (hv != vc.size())
		{
			if (cnt == vc[hv].first)
			{
				if (vc[hv].second == 'D')
				{
					index = (index + 1) % 4;
				}
				else if (index == 0)
				{
					index = 3;
				}
				else
				{
					index -= 1;
				}
				//printf("index : %d\n", index);
				hv++;

			}
		}
		if (tv != vc.size())
		{
			if (cnt - (len - 1) == vc[tv].first)
			{
				if (vc[tv].second == 'D')
				{
					ti = (ti + 1) % 4;
				}
				else if (ti == 0)
				{
					ti = 3;
				}
				else
				{
					ti -= 1;
				}
				//printf("ti : %d\n", ti);
				tv++;
			}
		}


	}

}

int main()
{
	scanf("%d", &N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a][b] = 2;
	}
	scanf("%d", &L);
	for (int i = 0; i < L; i++)
	{
		int a;
		char c;
		scanf("%d %c", &a, &c);
		vc.push_back({ a,c });
	}

	simul();
	printf("%d", cnt);

	return 0;
}
