#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

unordered_set<string> us;
int N, M;
vector<string> vc;

int main()
{
	int res = 0;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		string str = "";
		cin >> str;
		us.insert(str);
	}

	for (int i = 0; i < M; i++)
	{
		string str = "";
		cin >> str;
		if (us.find(str) != us.end())
		{
			vc.push_back(str);
			res++;
		}

	}
	printf("%d\n", res);

	sort(vc.begin(), vc.end());

	for (int i = 0; i < vc.size(); i++)
	{
		cout << vc[i] << "\n";
	}

	return 0;
}
