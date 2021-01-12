#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int coin[101];
int d[10001];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	d[0] = 1;

	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}

	sort(&coin[0], &coin[N]);

	for (int i = 0; i < N; i++) {
		
		int v = coin[i];

		for (int j = 1; j <= K; j++) {
			if (v > j)
				continue;
			else {
				d[j] += d[j - v];
			}

		}
	}

	printf("%d", d[K]);

	return 0;
}
