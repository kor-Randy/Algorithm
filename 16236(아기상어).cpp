#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<cmath>
using namespace std;

pair<int, int> s;
int big;
int N;
int arr[21][21];
int visit[21][21];
int si[7];
int xx[4] = { -1,0,0,1 };
int yy[4] = { 0,-1,1,0 };
int res, cnt, temp;
int can;

void countfish()
{
	can = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] != 0 && arr[i][j] != 9 && arr[i][j]<big)
			{
				can++;
			}
		}
	}
}

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first != b.first)
		return a.first < b.first;
	else
	{
		return a.second < b.second;
	}
}

void clear()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			visit[i][j] = -1;
		}
	}
}

void bfs()
{
	queue<pair<int, int>> q;
	q.push(s);

	visit[s.first][s.second] = 0;
	vector<pair<int, int>> vc;
	int len = 10000;
	while (1)
	{
		int x = q.front().first;
		int y = q.front().second;
		//printf("x : %d , y : %d\n", x, y);
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];

			if (visit[x][y] == len)
				break;
			else if (nx < 0 || nx >= N || ny < 0 || ny >= N||visit[nx][ny]!=-1)
				continue;
			else if (arr[nx][ny] > big)
			{
				//자기보다 큰 물고기
				continue;
			}
			else if(arr[nx][ny]==big || arr[nx][ny]==0)
			{
				//크기가 같아서 이동만 가능, 먹지는 못함
				visit[nx][ny] = visit[x][y]+1;
				q.push({ nx,ny });

			}
			else
			{
				//먹을 수 있음
				visit[nx][ny] = visit[x][y] + 1;//먹을때까지의 걸린 초(시간)
				len = visit[nx][ny];
				vc.push_back({ nx,ny });
			}

		}
		//printf("먹을 수 있는 갯수 : %d\n", vc.size());
		if (q.empty())
		{
			if (!vc.empty())
			{
				
				arr[s.first][s.second] = 0;
				

				sort(vc.begin(), vc.end(), compare);
				s = vc[0];//상어 위치 변경
				can--;//먹을수있는 총 갯수--
				cnt++;//상어 경험치 ++
				res += visit[vc[0].first][vc[0].second];//시간 더해주기
				arr[vc[0].first][vc[0].second] = 0; // 먹은자리 0으로
				
				//printf("res : %d 먹음\n",res);
				

			}
			else
			{
				temp = 1;
				return;
			}

			if (cnt >= big)
			{

				cnt -= big;//경험치 깍기
				big++;//크기 1증가
				countfish();
			}


			return;
		}
		

	}

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				s = { i,j };
				big = 2;
			}
			else
			{
				si[arr[i][j]]++;
			}
		}
	}
	countfish();
	
	while (can > 0)
	{
		clear();
		bfs();
		countfish();
		if (temp == 1)
			break;
	}

	cout << res;

	return 0;
}
