#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vc;

int main()
{
	for (int i = 0; i < 9; i++)
	{
		int a;
		scanf("%d", &a);
		vc.push_back(a);
	}

	sort(vc.begin(), vc.end());

	do {
		int temp = 0;
		for (int i = 0; i < 7; i++)
		{
			temp += vc[i];
		}
		if (temp == 100)
		{
			for (int i = 0; i < 7; i++)
			{
				printf("%d\n", vc[i]);
			}
			break;
		}

	} while (next_permutation(vc.begin(), vc.end()));

	return 0;
}
