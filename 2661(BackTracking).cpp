#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N;
int  temp, cnt;
int arr[4];

string str,res;

int dfs(int c,char past)
{

	if (c == N)
	{
		res = str;
		return 1;
	}
	

	
	for (int i = 1; i <= 3; i++)
	{
		if (past == i + '0')
			continue;
		str += i + '0';
		arr[i]++;
		if (dfs(c + 1,(i+'0')) == 1)
		{
			return 1;
		}
		arr[i]--;
		str.erase(str.size() - 1);
	}
	return 0;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dfs(0,'0');

	cout << res;

	return 0;
}
