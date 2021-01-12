#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string a;
string b;
int arr[1001][1001];

void getLength()
{
	
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

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	

	cin >> a;
	cin >> b;

	getLength();


	cout << arr[a.size()][b.size()];

	return 0;
}
