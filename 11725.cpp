#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int N;
vector<int> edge[100001];
int arr[100001];

void dfs(int n, int past) {
	
	arr[n] = past;
	//printf("%d\n", n);
	for (int i = 0; i < edge[n].size(); i++) {
		int next = edge[n][i];
		if(arr[next]==0)
		dfs(next, n);

	}

}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1,0);

	for (int i = 2; i <= N; i++) {
		printf("%d\n",arr[i]);
	}

	return 0;

}