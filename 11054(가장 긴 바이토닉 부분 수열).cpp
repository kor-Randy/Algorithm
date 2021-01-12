#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[1001];
int up[1001], down[1001];


int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
	
		cin >> arr[i];
		up[i] = down[i] = 1;
	
	}

	for (int i = 1; i < N; i++) {
	
		for (int j = 0; j < i; j++) {
			
			if (arr[i] > arr[j]) {
			
				up[i] = max(up[i], up[j] + 1);

			}

		}
	
	}

	for (int i = N-2; i >=0 ; i--) {

		for (int j = N-1; j > i; j--) {

			if (arr[i] > arr[j]) {

				down[i] = max(down[i], down[j] + 1);

			}

		}

	}
	int res = 0;
	for (int i = 0; i < N; i++) {
	
		res = max(res, up[i] + down[i]);
	
	}

	cout << res-1;

	return 0;
}
