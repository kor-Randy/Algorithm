#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[1025][1025];
int d[1025][1025];

int dp(int x, int y) {

	if (x == 1 && y == 1) {
		return d[x][y] = arr[x][y];
	}
	else if (x == 0 || y == 0) {
		return d[x][y] = 0;
	}
	else if (d[x][y] != 0) {
		return d[x][y];
	}
	else {
		d[x][y] = dp(x-1,y) + dp(x,y-1) - dp(x-1,y-1) + arr[x][y];
		return d[x][y];
	}
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		printf("%d\n", dp(c, d) - dp(a-1, d) - dp(c, b-1) + dp(a-1, b-1));
	}


	return 0;
}
