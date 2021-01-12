#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, S;
int arr[21];
int res;

void dfs(int index, int temp) {

	temp += arr[index];

	
	if (index == N) {
		return;
	}
	if (temp == S) {
		res++;


	}

	dfs(index + 1, temp - arr[index]);//이번 숫자를 포함X
	dfs(index + 1, temp);//이번 숫자를 포함 O


}


int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> S;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	dfs(0, 0);
	cout << res;

	

	return 0;
}
