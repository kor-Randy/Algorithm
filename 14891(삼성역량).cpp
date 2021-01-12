#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
#include<vector>
using namespace std;

string str;
char arr[5][8],tmp[5][8];
int K, res, temp, cnt;
vector<pair<int, int>> vc;

void spin(int num, int d)
{
	if (d == 1)
	{
		for (int i = 0; i < 8; i++)
		{
			if (i != 7)
				tmp[num][i + 1] = arr[num][i];
			else
				tmp[num][0] = arr[num][i];
		}
		
	}
	else
	{
		for (int i = 7; i >= 0; i--)
		{
			if (i != 0)
				tmp[num][i - 1] = arr[num][i];
			else
				tmp[num][7] = arr[num][i];
		}
		
	}
}


int main()
{
	for (int i = 1; i <= 4; i++)
	{
		cin >> str;
		
		for (int j = 0; j < 8; j++)
		{
			arr[i][j] = str[j];
		}

	}
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vc.push_back({ a,b });
	}

	for (int i = 0; i < K; i++)
	{
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				tmp[i][j] = arr[i][j];
			}
		}
		int n = vc[i].first;
		int d = vc[i].second;
		
		if (n == 1)
		{
			spin(1, d);
			if (arr[n][2] != arr[2][6])
			{
				
				if (arr[2][2] != arr[3][6])
				{
					if (arr[3][2] != arr[4][6])
					{
						spin(4, -d);
					}
					spin(3, d);
				}
				spin(2, -d);
			}
		}
		else if (n == 2)
		{
			spin(2, d);
			if (arr[1][2] != arr[n][6])
			{
				spin(1, -d);
			}

			if (arr[n][2] != arr[3][6])
			{

				if (arr[3][2] != arr[4][6])
				{
					spin(4, d);
				}
				spin(3, -d);
			}
		}
		else if (n == 3)
		{
			spin(3, d);
			if (arr[2][2] != arr[n][6])
			{
				if (arr[1][2] != arr[2][6])
				{
					spin(1, d);
				}
				spin(2, -d);
			}

			if (arr[n][2] != arr[4][6])
			{
				spin(4, -d);
			}
		}
		else
		{
			spin(4, d);
			if (arr[n][6] != arr[3][2])
			{

				if (arr[3][6] != arr[2][2])
				{
					if (arr[2][6] != arr[1][2])
					{
						spin(1, -d);
					}
					spin(2, d);
				}
				spin(3, -d);
			}
		}
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 8; j++)
			{
					arr[i][j] = tmp[i][j];
			}
		}

	}

	if (arr[1][0] == '1')
		res++;
	if (arr[2][0] == '1')
		res += 2;
	if (arr[3][0] == '1')
		res += 4;
	if (arr[4][0] == '1')
		res += 8;
	printf("%d", res);
	

	return 0;
}
