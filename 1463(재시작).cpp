#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int res;
int arr[1000001];
int dp(int n) {
	if (n == 1) {
		return arr[n] = 0;
	}
	else if (arr[n] != 1000001) {
		return arr[n];
	}
	else if (n % 6 == 0) {
		return arr[n] = min(min(dp(n / 3), dp(n / 2)),dp(n-1)) + 1;
	}
	else if (n % 3 == 0) {
		return arr[n] = min(dp(n / 3), dp(n - 1)) +1;
	}
	else if (n % 2 == 0) {
		return arr[n] = min(dp(n / 2), dp(n - 1)) +1;
	}
	else {
		return arr[n] = dp(n - 1) + 1;
	}
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;

	for (int i = 0; i <= N; i++)
		arr[i] = 1000001;
	printf("%d", dp(N));


	return 0;
}
