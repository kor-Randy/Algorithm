#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int coin[101];
int d[10001];
int res;

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= K; i++) {
		d[i] = 1000000;
		for (int j = 0; j < N; j++) {
			int v = coin[j];

			if (v > i) {
				//현재 동전이 i보다 클 때
				continue;
			}
			else {
				d[i] = min(d[i], d[i - v] + 1);
			}

		}

	}
	if (d[K] == 1000000)
		res = -1;
	else
		res = d[K];
	printf("%d", res);

	return 0;
}
