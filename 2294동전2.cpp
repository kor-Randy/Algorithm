#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int coin[101];
int dp[10001];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	sort(&coin[0], &coin[N]);

	if (coin[0] > M) {
		printf("-1");
		return 0;
	}
	dp[0] = 0;

	for (int i = 1; i <= M; i++) {
		//1원부터 비교
		dp[i] = 200000000;
		for (int j = 0; j < N; j++) {
			// 동전 차례대로
			if (coin[j] <= i) {
				//현재 가격보다 동전의 가격이 작으면
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
				// 현재까지의 최소 갯수 = min(현재 동전을 사용한 것, 이전 동전을 사용한 것)
			}

		}

	}
	if (dp[M] >= 200000000) {
		printf("-1");
	}else
		printf("%d", dp[M]);


	return 0;
}


