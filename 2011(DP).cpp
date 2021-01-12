#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int arr[5001];
int dp[5001];
string str;
int res,cnt;
void init()
{
	dp[0] = 1;
	for (int i = 1; i <= str.size(); i++)
	{
		int a = 0;
		a = arr[i];
		if (a > 0 && a < 10)
		{
				dp[i] = (dp[i-1]+dp[i]) % 1000000;
		}

		if (i == 1)
			continue;


		int temp = arr[i-1]* 10 + arr[i];


		if (temp >= 10 && temp <= 26)
		{
			dp[i] = (dp[i - 2] + dp[i]) % 1000000;
		}
	}
}


int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> str;
	for (int i = 0; i < str.size(); i++)
	{
		arr[i + 1] = str[i] - '0';
	}

	if (str[0] == '0')
	{
		cout << '0';
	}
	else
	{
		init();
		cout << dp[str.size()];
		
	}

	return 0;
}
