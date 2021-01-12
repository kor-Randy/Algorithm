#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


string str;
vector<int> vc;
int N,temp,res;
int length;
char bb[100001];

bool compare(int a, int b)
{
	return a > b;
}


int main()
{
	
	cin >> str;

	int length = str.length();
	
	for (int i = 0; i < length; i++)
	{
		vc.push_back(str[i] - '0');
		temp += vc[i];
	}

	sort(vc.begin(), vc.end(),compare);
	if (vc[vc.size() - 1] != 0 || temp % 3 != 0)
		printf("-1");
	else 
	{
		for (int i = 0;i < length; i++)
		{
		
			printf("%d", vc[i]);

		}
		
	}

	return 0;
}
