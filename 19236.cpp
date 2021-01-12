#include<iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>


using namespace std;

#define N 4

int res, cnt, temp;
pair<int, int> map[5][5];
pair<pair<int, int>, int> shark;
int xx[9] = { -1,-1,0,1,1,1,0,-1 };
int yy[9] = { 0,-1,-1,-1,0,1,1,1 };
//0 위 1 왼위 2 왼 3 왼아래 4 아래 5 오른아래 6 오른 7 오른위
// 상어를 fish에서는 100으로 표시

void changeFish(int eat, pair<pair<int, int>, int> s, pair<int,int> fish[5][5]) {

	pair<int, int> tt[5][5];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tt[i][j] = fish[i][j];
		}
	}

	for (int num = 1; num <= 16;num++) {
		//1번 물고기부터 차례대로 이동
		int fishIndex = num;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tt[i][j].first == fishIndex) {
					//물고기 위치 저장
					int x = i;
					int y = j;
					int d = tt[i][j].second;

					//물고기 회전
					for (int k = 0; k <= 7; k++) {
						//가야하는 방향(원래 방향 부터 )
						int fish_d = (d + k) % 8;
						
						//변경할 위치
						int nx = i + xx[fish_d];
						int ny = j + yy[fish_d];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
							//맵을 벗어나면 다시 회전
							continue;
						}
						else if (tt[nx][ny].first == 100) {
							//상어가 있는 곳이면
							continue;
						}
						else {
							//맵을 벗어나지 않으면
							//물고기 방향 저장
							tt[x][y].second = fish_d;
							//물고기 위치 변경

							pair<int, int> tmp;
							tmp = tt[x][y];
							tt[x][y] = tt[nx][ny];
							tt[nx][ny] = tmp;
							flag = true;
							break;
						}
					}
					
				}
				if (flag) {
					break;
				}
			}
			if (flag) {
				break;
			}
		}
	}
	//모든 물고기가 이동한 후

	
	//상어 이동
	int x = s.first.first;
	int y = s.first.second;
	int d = s.second;

	for (int i = 1; i < 4; i++) {
		//상어가 1칸갈지 2칸갈지 모두 비교해야함
		int nx = x + xx[d] * i;
		int ny = y + yy[d] * i;

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			//상어가 맵을 벗어나면 끝
			res = max(res, eat);
			return;
		}
		else if (tt[nx][ny].first == 0) {

			continue;
		}
		else {
			//상어가 먹음
			int eatNow = eat + tt[nx][ny].first;
			//먹은 후의 상어 상태 저장
			pair<pair<int, int>, int> newShark = { { nx,ny }, tt[nx][ny].second };
			//맵에 상어 표시
			pair<int, int> fishTemp;
			fishTemp = tt[nx][ny];

			tt[nx][ny] = { 100, tt[nx][ny].second };
			//물고기 이동
			tt[x][y].first = tt[x][y].second = 0;

			changeFish(eatNow, newShark, tt);

			tt[nx][ny] = fishTemp;
			//물고기 이동
			tt[x][y].first = 100;
		}

		if (i == 3) {
			return;
		}

	}

}

int main() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num, d;
			scanf("%d %d", &num, &d);
			map[i][j] = { num,d-1 };
		}
	}
	//0,0 위치에 삽입
	shark = { {0,0}, map[0][0].second};
	//먹은 물고기 번호 +
	res += map[0][0].first;
	//0,0 물고기 사라짐
	map[0][0].first = 100;
	map[0][0].second = 0;

	changeFish(res, shark, map);

	printf("%d", res);

	return 0;
}