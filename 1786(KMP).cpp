#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string T, P;
int f[1000001];
int res, cnt, temp;
vector<int> vc;
void getF()
{
	
	int j = 0;
	for (int i = 1; i < P.size(); i++)
	{
		while (j > 0 && P[i] != P[j])
		{
			j = f[j - 1];
		}

		if (P[i] == P[j])
		{
			f[i] = ++j;
		}

	}

}

void kmp()
{
	
	int j = 0;
	for (int i = 0; i < T.size(); i++)
	{
		while (j > 0 && T[i] != P[j])
		{
			j = f[j - 1];
		}

		if (T[i] == P[j])
		{
			if (j == P.size() - 1)
			{
				res++;
				vc.push_back(i - (P.size() - 1) +1); // i번째에서 (패턴의 길이-1)빼고 0부터 시작이므로 +1
				j = f[j];
			}
			else
			{
				++j;
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, T);
	getline(cin, P);

	getF();
	kmp();

	printf("%d\n", res);

	for (int i = 0; i < vc.size(); i++)
	{
		printf("%d\n", vc[i]);
	}

	return 0;
}
