#include<stdio.h>
#include<iostream>
#include<string>
#include<set>
using namespace std;

set<string> s;
int N;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1;
		cin >> s2;
		if (s2 == "enter")
			s.insert(s1);
		else
			s.erase(s1);
	}


	for (auto i = s.rbegin(); i != s.rend(); i++)
	{
		cout << *i << "\n";
	}

	return 0;
}
