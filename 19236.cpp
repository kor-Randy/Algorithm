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
//0 �� 1 ���� 2 �� 3 �޾Ʒ� 4 �Ʒ� 5 �����Ʒ� 6 ���� 7 ������
// �� fish������ 100���� ǥ��

void changeFish(int eat, pair<pair<int, int>, int> s, pair<int,int> fish[5][5]) {

	pair<int, int> tt[5][5];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tt[i][j] = fish[i][j];
		}
	}

	for (int num = 1; num <= 16;num++) {
		//1�� �������� ���ʴ�� �̵�
		int fishIndex = num;
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (tt[i][j].first == fishIndex) {
					//����� ��ġ ����
					int x = i;
					int y = j;
					int d = tt[i][j].second;

					//����� ȸ��
					for (int k = 0; k <= 7; k++) {
						//�����ϴ� ����(���� ���� ���� )
						int fish_d = (d + k) % 8;
						
						//������ ��ġ
						int nx = i + xx[fish_d];
						int ny = j + yy[fish_d];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
							//���� ����� �ٽ� ȸ��
							continue;
						}
						else if (tt[nx][ny].first == 100) {
							//�� �ִ� ���̸�
							continue;
						}
						else {
							//���� ����� ������
							//����� ���� ����
							tt[x][y].second = fish_d;
							//����� ��ġ ����

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
	//��� ����Ⱑ �̵��� ��

	
	//��� �̵�
	int x = s.first.first;
	int y = s.first.second;
	int d = s.second;

	for (int i = 1; i < 4; i++) {
		//�� 1ĭ���� 2ĭ���� ��� ���ؾ���
		int nx = x + xx[d] * i;
		int ny = y + yy[d] * i;

		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			//�� ���� ����� ��
			res = max(res, eat);
			return;
		}
		else if (tt[nx][ny].first == 0) {

			continue;
		}
		else {
			//�� ����
			int eatNow = eat + tt[nx][ny].first;
			//���� ���� ��� ���� ����
			pair<pair<int, int>, int> newShark = { { nx,ny }, tt[nx][ny].second };
			//�ʿ� ��� ǥ��
			pair<int, int> fishTemp;
			fishTemp = tt[nx][ny];

			tt[nx][ny] = { 100, tt[nx][ny].second };
			//����� �̵�
			tt[x][y].first = tt[x][y].second = 0;

			changeFish(eatNow, newShark, tt);

			tt[nx][ny] = fishTemp;
			//����� �̵�
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
	//0,0 ��ġ�� ����
	shark = { {0,0}, map[0][0].second};
	//���� ����� ��ȣ +
	res += map[0][0].first;
	//0,0 ����� �����
	map[0][0].first = 100;
	map[0][0].second = 0;

	changeFish(res, shark, map);

	printf("%d", res);

	return 0;
}