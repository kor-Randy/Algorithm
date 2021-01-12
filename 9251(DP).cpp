#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string a, b;
int res, temp, cnt;
int check[1001][1001];

int dp(int first, int second)
{
	
	if (first == 0 && second == 0)
	{
		if (a[first] == b[second])
		{
			check[first][second] = 1;
		}
		else
		{
			check[first][second] = 0;
		}
		return check[first][second];
	}
	else if (first == 0)
	{
		if (a[first] == b[second])
		{
			check[first][second] = 1;
		}
		else
		{
			check[first][second] = dp(first,second-1);
		}
		return check[first][second];
	}
	else if (second == 0)
	{
		if (a[first] == b[second])
		{
			check[first][second] = 1;
		}
		else
		{
			check[first][second] = dp(first - 1 , second);
		}
		return check[first][second];
	}
	else if (check[first][second] != -1)
	{
		return check[first][second];
	}
	else
	{
		if (a[first] == b[second])
		{
			return check[first][second] = dp(first - 1, second - 1)+1;

		}
		else
		{
			return check[first][second] = max(dp(first - 1, second), dp(first, second - 1));
		}
	}

}


int main()
{
	cin >> a;
	cin >> b;

	memset(check, -1, sizeof(check));
	//printf("%d,%d", a.length(), b.length());

	

	printf("%d", dp(a.length()-1,b.length()-1));

	

	return 0;
}
