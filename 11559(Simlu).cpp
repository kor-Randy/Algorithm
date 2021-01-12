#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
using namespace std;

string str[13];
int visit[13][7];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int res, temp, cnt;

vector<pair<int, int>> vc;
void clearvisit()
{
	
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			visit[i][j] = 0;
		}
	}

}

void bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	vc.push_back({ x,y });
	visit[x][y] = 1;
	cnt = 1;

	while (1)
	{
		x = q.front().first;
		y = q.front().second;
		char a = str[x][y];
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 12||visit[nx][ny]!=0)
				continue;
			else
			{
				char na = str[nx][ny];
				if (na == a)
				{
					cnt++;
					visit[nx][ny] = 1;
					vc.push_back({ nx,ny });
					q.push({ nx,ny });
				}
				
			}

		}
		if (q.empty())
			break;

	}

}

void down()
{
	char dot = '.';

	for (int i = 0; i < 6; i++)
	{
		//i는 y
		for (int j = 11; j >=0 ; j--)
		{
			if (str[j][i] == 'X')
			{
				//삭제된 것이면
				for (int k = j; k >= 0; k--)
				{
					//맨위에 .넣고 나머지 한칸씩 내리기
					if (k == 0)
						str[k][i] = dot;
					else
						str[k][i] = str[k - 1][i];

				}
				j++;

			}
		}
	}
	

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 12; i++)
	{
		cin >> str[i];
	}

	
	

	while (1)
	{
		bool flag = false;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				char nowch = '/';
				cnt = 1;
				if (str[i][j] != '.' && str[i][j]!='X' && visit[i][j] == 0)
				{
					//bfs해서 visit을 1로 바꾸기
					nowch = str[i][j];
					bfs(i, j);
				}

				if (cnt >= 4)
				{
					flag = true;
					//4개가 넘어간 것들 X로 바꿔주기

					for (int i = 0; i < vc.size(); i++)
					{
						str[vc[i].first][vc[i].second] = 'X';
					}
					
				}
				vc.clear();

			}
		}
		
		down();//바꿔주기

		clearvisit();
		
		

		if (flag == false)
			break;
		else
		{

			res++;
		}

	}

	printf("%d", res);

	return 0;
}
