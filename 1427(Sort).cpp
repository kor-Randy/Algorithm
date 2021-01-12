#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

bool compare(int a, int b)
{
	return a > b;
}


int main()
{
	vector<int> vc;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		vc.push_back(str[i] - '0');
	}
	sort(vc.begin(), vc.end(),compare);

	for (int i = 0; i < vc.size(); i++)
	{
		printf("%d", vc[i]);
	}




	return 0;
}