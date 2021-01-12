#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;
int map[51][51];
int check[51][51];
int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };
int cnt, temp, res;
int zero;
vector<pair<int, int>> virus;
vector<int> pick;

void bfs() {
	queue<pair<int, int>> q;

	for (int i = 0; i < pick.size(); i++) {
		q.push({ virus[pick[i]].first, virus[pick[i]].second });
		check[virus[pick[i]].first][virus[pick[i]].second] = 0;
	}

	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + xx[i];
			int ny = y + yy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
				continue;
			}
			else if (check[nx][ny] != -1) {
				//한번 들렸던 곳이면 무시
				continue;
			}
			else if (map[nx][ny] == 1) {
				//벽이면 무시
				continue;
			}
			else {
				q.push({ nx,ny });
				check[nx][ny] = check[x][y] + 1;
				if (map[nx][ny] == 0) {
					temp = check[nx][ny];
					cnt++;
				}
			}
		}
	}
	if (cnt == zero&&temp < res) {
		res = temp;
	}
}

void clearCheck() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			check[i][j] = -1;
		}
	}
	cnt = 0;
	temp = 0;
}

void pickVirus(int c, int index) {
	if (c == M) {
		clearCheck();
		bfs();
		return;
	}

		for (int i = index; i < virus.size(); i++) {
			pick.push_back(i);
			pickVirus(c+1, i+1);
			pick.pop_back();
		}
	
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	res = 987654321;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0)
				zero++;
			else if (map[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	pickVirus(0,0);

	if (res != 987654321)
		printf("%d", res);
	else
		printf("-1");

	return 0;
}
