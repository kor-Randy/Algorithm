#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int N;
int visit[16][16];
int temp, cnt, res;
vector<pair<int,int>> vc;
//못 가는 곳은 그 밑으로 가지 않는다.
//갈 수 있는 곳은 그 밑으로 간다.
void dfs(int x, int y)
{

	if (x == N - 1)
	{
		//맨 아래 행에 도착하면
		res++;
		//printf("x : %d , y : %d\n", x, y);
		//printf("\nres++\n\n");
		return;
	}
	else
	{
		
		

		int nx = x + 1;
		for (int ny = 0; ny < N; ny++)
		{
			int temp = 0;
			for (int i = 0; i < vc.size(); i++)
			{

				if (vc[i].first == nx || vc[i].second == ny || (abs(ny - vc[i].second) == abs(nx - vc[i].first)))
				{
					//이미 골른 것들과 행이 같거나, 열이 같거나, 대각선인 경우
					temp = 1;
					break;
				}
				
			}
			if (temp == 0)
			{

				//printf("nx : %d , ny : %d\n", nx, ny);
				vc.push_back({ nx,ny });
				dfs(nx, ny);
				vc.pop_back();
			
			}

				
		}

	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		//printf("0,%d 시작\n", i);
		//printf("size : %d\n", vc.size());
		vc.push_back({ 0,i });
		dfs(0, i);
		vc.pop_back();
		//printf("%d\n", res);


	}

	printf("%d", res);

	return 0;
}
