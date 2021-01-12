#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string a, b;
int arr[1001][1001];
int check[1001];
string str;
void dp()
{

	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (i == 0 && j == 0)
				continue;
			else if (i == 0)
			{
				if (a[i] == b[j])
				{
					arr[i][j] = 1;
				}
				else
				{
					arr[i][j] = arr[i][j - 1];
				}
			}
			else if (j == 0)
			{
				if (a[i] == b[j])
				{
					arr[i][j] = 1;
				}
				else
				{
					arr[i][j] = arr[i - 1][j];
				}
			}
			else
			{
				if (a[i] == b[j])
				{
					arr[i][j] = arr[i - 1][j - 1] + 1;
				}
				else
				{
					arr[i][j] = max(arr[i - 1][j], arr[i][j - 1]);
				}
			}
		}
	}

}

int main()
{
	cin >> a;
	cin >> b;

	if (a[0] == b[0])
		arr[0][0] = 1;


	dp();

	printf("%d\n", arr[a.size() - 1][b.size() - 1]);

	if (arr[a.size() - 1][b.size() - 1] == 0)
		return 0;

	int i = a.size()-1;
	int j = b.size()-1;

	while (arr[i][j]!=0)
	{
		if (arr[i][j - 1] == arr[i][j] && j>=1)
		{
			j--;
		}
		else if (arr[i - 1][j] == arr[i][j] && i>=1)
		{
			i--;
		}
		else
		{
			check[i] = 1;
			i--;
			j--;

			if (i < 0 || j < 0)
				break;
		}
	}


	for (int k = 0; k < a.size(); k++)
	{
		if (check[k] == 1)
			str += a[k];
	}
	cout << str;
	return 0;
}
