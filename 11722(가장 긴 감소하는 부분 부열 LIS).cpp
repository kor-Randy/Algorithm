#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, S;
int arr[1001];
int dp[1001];
int res;


int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++) {

		for (int j = 0; j < i; j++) {

			if (arr[i] < arr[j]) {
				//j번째 수보다 작으면
				dp[i] = max(dp[i], dp[j] + 1);
			}

		}

	}

	sort(&dp[0], &dp[N]);

	res = dp[N - 1];
	cout << res;



	return 0;
}
