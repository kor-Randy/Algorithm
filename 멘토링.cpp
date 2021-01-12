#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str = " ";
		
		for (int j = 0; j <= i; j++)
		{
			cout << " ";
		}

		for (int j = 0; j < n; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}

	return 0;
}
