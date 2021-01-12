#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M, V;
vector<int> vc[1001];
int visit[1001];

void dfs(int n) {
	
	printf("%d ", n);
	visit[n] = 1;

	for (int i = 0; i < vc[n].size(); i++) {
		int nx = vc[n][i];

		if (visit[nx] == 0) {
			dfs(nx);
		}

	}

}

void bfs(int n) {
	queue<int> q;
	q.push(n);
	visit[n] = 1;
	while (1) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < vc[x].size(); i++) {
			int nx = vc[x][i];


			if (visit[nx] == 0) {
				visit[nx] = 1;
				q.push(nx);
			}

		}
		if (q.empty()) {
			break;
		}
	}

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		vc[a].push_back(b);
		vc[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sort(vc[i].begin(), vc[i].end());
	}

	dfs(V);
	printf("\n");

	for (int i = 1; i <= N; i++) {
		visit[i] = 0;
	}

	bfs(V);

	return 0;
}
