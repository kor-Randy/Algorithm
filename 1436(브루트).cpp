#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N;
int res;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	int num = 666;

	while (1) {
		string str = to_string(num);
		if (str.find("666") != -1) {
			res++;
		}
		if (res == N) {
			break;
		}
		num++;
	}
	printf("%d", num);

	return 0;
}
