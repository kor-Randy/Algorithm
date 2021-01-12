#include <string>
#include <vector>
#include<algorithm>
//20/0000/0000/0000

using namespace std;
long long total;
vector<int> vc;

int getMin() {
	int temp = 200000000;
	for (int i = 0; i<vc.size(); i++) {
		if (vc[i] != 0) {
			//�� ���� ���� ��쿡
			temp = min(temp, vc[i]);
		}
	}

	return temp;
}

int getSize() {
	int size = 0;
	for (int i = 0; i<vc.size(); i++) {
		if (vc[i] != 0) {
			//�� ���� ���� ��쿡
			size++;
		}
	}
	return size;
}

void minusMin(int min) {
	for (int i = 0; i<vc.size(); i++) {
		if (vc[i] != 0) {
			//�� ���� ���� ��쿡
			vc[i] -= min;
		}
	}
}

int main() {
	vector<int> food;
	long long k;

	food.push_back(3);
	food.push_back(1);
	food.push_back(2);
	k = 5;
	int answer = 0;
	vc = food;
	for (int i = 0; i<food.size(); i++) {
		//�� �Ծ���ϴ� �ð� ���ϱ�
		total += food[i];
	}

	if (total <= k) {
		return -1;
	}

	//k�� �̺�Ž���Ѵ�

	bool flag = false;
	while (1) {
		//food�� min�� ���Ѵ� -> 2000
		int min = getMin();
		int size = getSize();

		if (k == 0) {
			//���� �ִ� �͵� �� 1���� index�� ���� �����̴�
			for (int i = 0; i<vc.size(); i++) {
				//�� �Ծ���ϴ� �ð� ���ϱ�
				if (vc[i] != 0) {
					answer = i;
					break;
				}
			}

			break;

		}
		else if (k<min*size) {
			//���� �纸�� ���� ���
			int num = k%size;
			int cnt = 0;
			for (int i = 0; i<vc.size(); i++) {
				//�� �Ծ���ϴ� �ð� ���ϱ�
				if (vc[i] != 0) {
					if (cnt == num) {
						answer = i;
						break;
					}
					cnt++;
				}
			}
			break;


		}
		else {

			//food���� min�� �A�� -> 2000
			minusMin(min);

			//���� �ð��� ���� 
			k -= min*size;
			printf("%d ", k);
		}


	}


	printf("\n%d", answer);


	return 0;
}