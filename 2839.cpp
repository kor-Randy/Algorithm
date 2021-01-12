#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{
	
	int a,count;

	cin >> a;
	count = 0;
	while (a > 0)
	{
		if (a % 5 == 0)
		{
			a -= 5;
			count++;
		}
		else if (a % 3 == 0)
		{
			a -= 3;
			count++;

		}
		else if (a > 5)
		{
			a -= 5;
			count++;
		}
		else
		{
			cout << -1;
			return 0;
		}
		
	}
	cout << count;

	return 0;
}