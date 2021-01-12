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
			//다 먹지 않은 경우에
			temp = min(temp, vc[i]);
		}
	}

	return temp;
}

int getSize() {
	int size = 0;
	for (int i = 0; i<vc.size(); i++) {
		if (vc[i] != 0) {
			//다 먹지 않은 경우에
			size++;
		}
	}
	return size;
}

void minusMin(int min) {
	for (int i = 0; i<vc.size(); i++) {
		if (vc[i] != 0) {
			//다 먹지 않은 경우에
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
		//총 먹어야하는 시간 구하기
		total += food[i];
	}

	if (total <= k) {
		return -1;
	}

	//k를 이분탐색한다

	bool flag = false;
	while (1) {
		//food의 min을 구한다 -> 2000
		int min = getMin();
		int size = getSize();

		if (k == 0) {
			//현재 있는 것들 중 1번쨰 index를 먹을 차례이다
			for (int i = 0; i<vc.size(); i++) {
				//총 먹어야하는 시간 구하기
				if (vc[i] != 0) {
					answer = i;
					break;
				}
			}

			break;

		}
		else if (k<min*size) {
			//먹을 양보다 작은 경우
			int num = k%size;
			int cnt = 0;
			for (int i = 0; i<vc.size(); i++) {
				//총 먹어야하는 시간 구하기
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

			//food에서 min을 뺸다 -> 2000
			minusMin(min);

			//먹을 시간을 뺀다 
			k -= min*size;
			printf("%d ", k);
		}


	}


	printf("\n%d", answer);


	return 0;
}