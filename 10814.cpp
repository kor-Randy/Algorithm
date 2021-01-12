#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

using namespace std;
int N;
vector<pair<int, string>> vc;

bool compare(pair<int, string> a, pair<int, string> b)
{
		return a.first < b.first;
	
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 속도 향상 위해
	int aa = 0;
	string str = "";
	cin >> N;
	for (int i = 0; i<N; i++)
	{
		cin >> aa;
		cin >> str;
		vc.push_back({ aa,str });
	}

	stable_sort(vc.begin(), vc.end(),compare);

	for (int i = 0; i<N; i++)
	{
		cout << vc[i].first << " " << vc[i].second << "\n";
	}

	return 0;
}