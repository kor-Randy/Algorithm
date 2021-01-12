#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string a, b;
int res,temp,cnt;
int aa, bb;



int main()
{
	res = 51;
	cin >> a;
	cin >> b;

	aa = a.length();
	bb = b.length();

	for (int i = 0; i <= bb - aa; i++)
	{
		cnt = 0;
		for (int j = 0; j < aa; j++)
		{
			if (a[j] != b[i + j])
				cnt++;
		}
		res = min(res, cnt);
	}
	printf("%d", res);

	return 0;
}
