#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[101];
int ca[3];
int res;
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> ca[0] >> ca[1] >> ca[2];

	for (int i = 0; i < 3; i++)
	{
		int a, b;
		cin >> a >> b;

		for (int i = a; i < b; i++)
		{
			arr[i]++;
		}

	}


	for (int i = 0; i < 101; i++)
	{
		switch (arr[i])
		{
			case 0: 
			{
				break; 
			}
			case 1:
			{
				res += ca[0];
				break;
			}
			case 2:
			{
				res += ca[1]*2;
				break;
			}
			case 3:
			{
				res += ca[2]*3;
				break;
			}

		}
	}
	printf("%d", res);
	return 0;
}
