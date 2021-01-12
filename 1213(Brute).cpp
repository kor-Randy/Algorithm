#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string str;
int arr[30];
int temp, cnt;
string res;
int main()
{
	cin >> str;

	sort(&str[0], &str[str.size()]);

	for (int i = 0; i < str.size(); i++)
	{
		arr[str[i] - 'A']++;
		//printf("%d , %d\n", str[i] - 'A', arr[str[i] - 'A']);
	}
	for (int i = 0; i < 27; i++)
	{
		if (arr[i] % 2 == 1)
		{
			if(temp==0)
				temp = 1;
			else
			{
				printf("I'm Sorry Hansoo");
				return 0;
			}
		}
	}

	for (int i = 0; i < 27; i++)
	{
		if (arr[i] % 2 == 0 && arr[i] > 0)
		{
			for (int j = 0; j < arr[i] / 2; j++)
			{
				res += (i + 'A');
			}
		}
		else if(arr[i]%2==1)
		{
			for (int j = 0; j < (arr[i]-1)/2; j++)
			{
				res += (i + 'A');
			}
		}
	}

	for (int i = 0; i < 27; i++)
	{
		if (arr[i] % 2 == 1)
		{
			
				res += (i + 'A');
		}
	}

	for (int i = 26; i >=0; i--)
	{
		if (arr[i] % 2 == 0 && arr[i] > 0)
		{
			for (int j = 0; j < arr[i] / 2; j++)
			{
				res += (i + 'A');
			}
		}
		else if (arr[i] % 2 == 1)
		{
			for (int j = 0; j < (arr[i] - 1) / 2; j++)
			{
				res += (i + 'A');
			}
		}
	}
	cout << res;
	return 0;
}
