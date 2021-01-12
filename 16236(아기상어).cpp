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
				//�ڱ⺸�� ū �����
				continue;
			}
			else if(arr[nx][ny]==big || arr[nx][ny]==0)
			{
				//ũ�Ⱑ ���Ƽ� �̵��� ����, ������ ����
				visit[nx][ny] = visit[x][y]+1;
				q.push({ nx,ny });

			}
			else
			{
				//���� �� ����
				visit[nx][ny] = visit[x][y] + 1;//������������ �ɸ� ��(�ð�)
				len = visit[nx][ny];
				vc.push_back({ nx,ny });
			}

		}
		//printf("���� �� �ִ� ���� : %d\n", vc.size());
		if (q.empty())
		{
			if (!vc.empty())
			{
				
				arr[s.first][s.second] = 0;
				

				sort(vc.begin(), vc.end(), compare);
				s = vc[0];//��� ��ġ ����
				can--;//�������ִ� �� ����--
				cnt++;//��� ����ġ ++
				res += visit[vc[0].first][vc[0].second];//�ð� �����ֱ�
				arr[vc[0].first][vc[0].second] = 0; // �����ڸ� 0����
				
				//printf("res : %d ����\n",res);
				

			}
			else
			{
				temp = 1;
				return;
			}

			if (cnt >= big)
			{

				cnt -= big;//����ġ ���
				big++;//ũ�� 1����
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
