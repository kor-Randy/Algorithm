#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[10][1001];
int res;

int dp(int n, int cnt) {
	if (cnt == 1) {
		return arr[n][cnt] = 1;
	}
	else if (arr[n][cnt] != 0) {
		return arr[n][cnt] % 10007;
	}
	else {
		for (int i = n; i < 10; i++) {
			arr[n][cnt] += dp(i, cnt - 1);
			arr[n][cnt] % 10007;
		}
	}
	return arr[n][cnt] % 10007;
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < 10; i++) {

		res += dp(i,N);
		res %= 10007;
	}
	cout << res;


	return 0;
}
