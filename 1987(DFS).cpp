#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int R, C;
char arr[21][21];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int res, cnt, temp;
int alp[28];

void dfs(int x, int y,int c)
{

	res = max(res, c);
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xx[i];
			int ny = y + yy[i];
			

			if (nx < 0 || nx >= R || ny < 0 || ny >= C )
				continue;
			else
			{
				char na = arr[nx][ny];
				if (alp[na - 'A'] == 0) 
				{
					alp[na - 'A'] = 1;
					dfs(nx, ny, c + 1);
					alp[na - 'A'] = 0;
				}
			}

		}

	

}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> R>> C;

	for (int i = 0; i < R; i++)
	{
		cin >> arr[i];
	}
	alp[arr[0][0] - 'A'] = 1;
	dfs(0, 0, 1);
	printf("%d", res);

	return 0;
}
