#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

unordered_map<string,int> um;
int T, N;
long long res, temp, cnt;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		if (N == 0)
		{
			printf("0\n");
			continue;
		}

		for (int j = 0; j < N; j++)
		{
			string a, b;
			cin >> a>>b;

				um[b]++;

		}
		

		res = 1;

		for (auto data : um)
		{
			res *= (data.second+1);
		}
		res -= 1;
		printf("%ld\n", res);

		um.clear();

	}


	return 0;
}
