#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N;
int arr[101][101];
int visit[101][101];
int temp, res, cnt;
bool value[101];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { -1,1,0,0 };
int h;

void bfs(int row, int col) {
	
	queue<pair<int, int>> q;
	q.push({ row,col });

	while (true) {
	
		int x = q.front().first;
		int y = q.front().second;
		visit[x][y] = 1;
		q.pop();

		for (int i = 0; i < 4; i++) {
			
			int nx = x + xx[i];
			int ny = y + yy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
				continue;
			}
			else if (arr[nx][ny] <= h) {
				continue;
			} 
			else if (visit[nx][ny] == 1) {
				continue;
			}
			else {
				
				q.push({ nx,ny });
				visit[nx][ny] = 1;

			}

		}

		if (q.empty()) {
			break;
		}

	}

}

void clear() {

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N; j++) {

			visit[i][j] = 0;

		}
	}

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 101; i++) {
		value[i] = true;
	}

	cin >> N;

	for (int i = 0; i < N; i++){

		for (int j = 0; j < N; j++) {
		
			int height = 0;
			cin >> height;
			arr[i][j] = height;
			
		
		}
	}

	for (int i = 0; i < 101; i++) {
		h = i;
		cnt = 0;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				
				if (visit[j][k] == 0 && arr[j][k] > h) {
					bfs(j, k);
					cnt++;
				}

			}
		}
		clear();
		res = max(res, cnt);

	}

	printf("%d", res);



	return 0;
}
