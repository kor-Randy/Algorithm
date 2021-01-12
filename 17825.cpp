#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[10];
int map[8][6] = { {0,2,4,6,8,10},{10,12,} };
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}

	return 0;
}
