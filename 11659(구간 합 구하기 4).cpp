#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int num[100001];
int d[100001];
int res;

int dp(int n) {
	if(n == 0) {
		return 0;
	}
	else if (n == 1) {
		return d[n] = num[n];
	}
	else if (d[n] != 0) {
		return d[n];
	}
	else {
		return d[n] = dp(n - 1) + num[n];
	}
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		printf("%d\n", dp(b) - dp(a - 1));
	}



	return 0;
}
