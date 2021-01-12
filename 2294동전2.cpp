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
		//1������ ��
		dp[i] = 200000000;
		for (int j = 0; j < N; j++) {
			// ���� ���ʴ��
			if (coin[j] <= i) {
				//���� ���ݺ��� ������ ������ ������
				dp[i] = min(dp[i], dp[i - coin[j]] + 1);
				// ��������� �ּ� ���� = min(���� ������ ����� ��, ���� ������ ����� ��)
			}

		}

	}
	if (dp[M] >= 200000000) {
		printf("-1");
	}else
		printf("%d", dp[M]);


	return 0;
}


