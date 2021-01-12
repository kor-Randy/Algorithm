#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<deque>
#include<queue>
using namespace std;

int N, K;
int coin[101];
int dp[10001];
unordered_set<int> us;
deque<int> dq;
pair<int, int> p;
int main() {
	queue<int> q;
	q
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	dq.end();
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
	
	for (auto it = us.begin(); it != us.end(); it++) {
		us.erase(it);
	}

	sort(&coin[0], &coin[N]);

	dp[0] = 1;

	for (int i = 1 ; i <= K; i++) {
		
		for (int j = 0; j < N; j++) {
			int v = coin[j];
			if (v > i) {
				break;
			}
			else {
				dp[i] += dp[i - v];
			}
		
		}

	}

	printf("%d", dp[K]);


	return 0;
}

