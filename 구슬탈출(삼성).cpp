#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

int N, M;
string arr[11];
int visit[11][11][11][11];
int temp, res;
int xx[4] = { -1,1,0,0 };
int yy[4] = { 0,0,-1,1 };
pair<int, int> r, b, g;
bool r_flag, b_flag;

pair<int,int> go(int index, int type, pair<int,int> other) {
	int x, y;

	if (type == 0) {
		x = r.first;
		y = r.second;
	}
	else {
		x = b.first;
		y = b.second;
	}

	while (1) {
		if (arr[x + xx[index]][y + yy[index]] == '#') {
			//������ �� ���� ���̸�
			break;
		}
		if (type == 0) {
			//�ڽ��� red
			if (x + xx[index] == other.first && y + yy[index] == other.second) {
				//������ �� ���� blue������ ������
				break;
			}
		}
		else {
			//�ڽ��� blue
			if (x + xx[index] == other.first && y + yy[index] == other.second) {
				//������ �� ���� red������ ������
				break;
			}
		}
		if (x + xx[index] == g.first && y + yy[index] == g.second) {
			//������ �� ���� ����
			//���� �Ŀ� ������ �ʰ� ������ ��
			if (type == 0) {
				r_flag = true;
				return { 0,0 };
			}
			else {
				b_flag = true;
				return { 0,0 };
			}
		}

		x += xx[index];
		y += yy[index];

	}

	
	return { x,y };

	

}

int bfs(pair<int,int> rr, pair<int,int> bb) {
	queue<pair<pair<int, int>, pair<int, int>>> q;
	queue<int> countQ;
	q.push({ rr,bb });
	countQ.push(1);

	visit[rr.first][rr.second][bb.first][bb.second] = 1;

	while (1) {
		int rx = q.front().first.first;
		int ry = q.front().first.second;
		r = q.front().first;

		int bx = q.front().second.first;
		int by = q.front().second.second;
		b = q.front().second;
		q.pop();

		int cnt = countQ.front();
		countQ.pop();

		if (cnt > 10) {
			return -1;
		}

		for (int i = 0; i < 4; i++) {
			pair<int, int> nr, nb;
			nr = r;
			nb = b;
			r_flag = b_flag = false;
			if (i == 0) {
				if (ry == by){
					if (rx < bx) {
						//rx����
						nr = go(i, 0,nb);
						nb = go(i, 1,nr);
					}
					else {
						//bx����
						nb = go(i, 1,nr);
						nr = go(i, 0,nb);
					}
				}
				else {
					//�׳� �Ѵ� ����
					nr = go(i, 0,nb);
					nb = go(i, 1,nr);
				}
			}
			else if (i == 1) {
				if (ry == by) {
					if (rx < bx) {
						//bx����
						nb = go(i, 1,nr);
						nr = go(i, 0,nb);
					}
					else {
						//rx����
						nr = go(i, 0,nb);
						nb = go(i, 1,nr);
					}
				}
				else {
					//�Ѵ�
					nr = go(i, 0,nb);
					nb = go(i, 1,nr);
				}
			}
			else if (i == 2) {
				if (rx == bx) {
					if (ry < by) {
						//ry����
						nr = go(i, 0,nb);
						nb = go(i, 1,nr);
					}
					else {
						//by����
						nb = go(i, 1,nr);
						nr = go(i, 0,nb);
					}
				}
				else {
					//�Ѵ�
					nr = go(i, 0,nb);
					nb = go(i, 1,nr);
				}
			}
			else {
				if (rx == bx) {
					if (ry < by) {
						//by����
						nb = go(i, 1,nr);
						nr = go(i, 0,nb);
					}
					else {
						//ry����
						nr = go(i, 0,nb);
						nb = go(i, 1,nr);
					}
				}
				else {
					//�Ѵ�
					nr = go(i, 0,nb);
					nb = go(i, 1,nr);
				}
			}

			if (r_flag) {
				if (b_flag) {
					//����
					continue;
				}
				else {
					return cnt;
					//����
				}
			}
			if (b_flag) {
				continue;
				//����
			}

			
			if (visit[nr.first][nr.second][nb.first][nb.second] == 1) {
				continue;
			}
			else{
				//printf("���� : %d,%d  , �Ķ� : %d,%d\n", nr.first, nr.second, nb.first, nb.second);
				q.push({ {nr.first,nr.second},{nb.first,nb.second} });
				//printf("ī��Ʈ ���� : %d\n", cnt+1);
				countQ.push(cnt + 1);
				visit[nr.first][nr.second][nb.first][nb.second] = 1;
			}

		}

		if (q.empty()) {
			return -1;
		}

	}


}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'R') {
				r = { i,j };
			}
			if (arr[i][j] == 'B') {
				b = { i,j };
			}
			if (arr[i][j] == 'O') {
				g = { i,j };
			}
		}
	}

	

	printf("%d", bfs(r, b));


	return 0;
}
