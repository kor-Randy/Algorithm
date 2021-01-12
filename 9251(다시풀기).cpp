#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string a, b;

int arr[1001][1001];
int res, temp;

int main()
{
	cin >> a;
	cin >> b;

	for (int i = 0; i <= a.size(); i++)
	{
		arr[i][0] = 0;
	}
	for (int i = 0; i <= b.size(); i++)
	{
		arr[0][i] = 0;
	}

	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i-1] == b[j-1])
			{
				arr[i][j] = arr[i - 1][j - 1] + 1;
			}
			else
			{
				arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
			}
		}
	}

	printf("%d", arr[a.size()][b.size()]);


	return 0;
}
