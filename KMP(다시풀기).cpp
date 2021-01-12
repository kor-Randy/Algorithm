#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

string T, P;

int f[1000001];
int res;
vector<int> vc;
void getFail()
{
	int index = 0;
	for (int i = 1; i < P.size(); i++)
	{
		while (index > 0 && P[i] != P[index])
		{
			index = f[index - 1];
		}

		if (P[i] == P[index])
		{
			f[i] = ++index;
		}
	}

}

void kmp()
{
	
	int index = 0;

	for (int i = 0; i < T.size(); i++)
	{
		
		while (index > 0 && T[i] != P[index])
		{
			index = f[index - 1];
		}

		if (T[i] == P[index])
		{
			if (index == P.size() - 1)
			{
				res++;
				vc.push_back(i - (P.size() - 1));

				index = f[index];

			}
			else
			{
				++index;
			}
		}


	}

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	getline(cin, T);
	getline(cin, P);

	getFail();
	kmp();

	printf("%d\n", res);
	for (int i = 0; i < vc.size(); i++)
	{
		printf("%d\n", vc[i]+1);
	}


	return 0;
}
