#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// adaabc
//aababbc

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a, b;
	cin >> a;
	cin >> b;
	int lenA = a.size();
	int lenB = b.size();
	int res = 100;

	for (int i = 0; i <= lenB - lenA; i++) {
		int nowIndex = i;
		int temp = 0;

		for (int j = 0; j < lenA; j++) {
			if (a[j] == b[nowIndex+j]) {
				temp++;
			}
		}
		res = min(res, lenA - temp);
	}

	printf("%d", res);


	return 0;
}
