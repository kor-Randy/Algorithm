#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

string str;
int xx[8] = { -2,-1,1,2,-2,-1,1,2 };
int yy[8] = { -1,-2,-2,-1,1,2,2,1 };
int res, temp, cnt;
int visit[7][7];
vector<pair<int, int>> vc;
void simul()
{
	for (int i = 0; i < 36; i++)
	{
		int x = vc[i].first;
		int y = vc[i].second;
		if (visit[x][y] == 1)
		{
			printf("Invalid");
			return;
		}
		visit[x][y] = 1;

		
	//	printf("i : %d\n", i);
		for (int j = 0; j < 8; j++)
		{
			
			int nx = x + xx[j];
			int ny = y + yy[j];

			
			if (nx < 0 || nx >= 6 || ny < 0 || ny >= 6)
			{
				if (j == 7)
				{
					//7개를 다 돌았는데 마지막까지 없었고 마지막이 범위 밖
					printf("Invalid");
					return;
				}

				continue;
			}

			if (i<35 && make_pair(nx,ny)==vc[i+1])
			{
				//갈 수 있는 곳
				break;
			}
			else if (i == 35 && make_pair(nx,ny)==vc[0])
			{
				//마지막에서 시작위치로 갈 수 있다
				printf("Valid");
				return;
			}
			else
			{
				if (j == 7)
				{
					//7개동안 갈 수 없었다.
					printf("Invalid");
					return;
				}
			}

		}

	}
}

int main()
{
	for (int i = 0; i < 36; i++)
	{
		cin >> str;

		vc.push_back({ str[0] - 'A',str[1] - '1' });
	}

	simul();

	return 0;
}
