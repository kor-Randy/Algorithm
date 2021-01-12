#include<vector>
#include<iostream>

using namespace std;
vector<int> vc;
int arr[101];
void vccheck(vector<int> vc) {

	for (int i = 0; i < vc.size(); i++) {
		vc[i]++;
		printf("%d ", vc[i]);
	}
	printf("\n");
}

void arrCheck(int a[]) {
	for (int i = 0; i < 100; i++) {
		arr[i]++;
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {

	for (int i = 0; i < 100; i++) {
		vc.push_back(i);
		arr[i] = i;
	}

	vccheck(vc);

	for (int i = 0; i < vc.size(); i++) {
		printf("%d ", vc[i]);
	}
	printf("\n\n");
	arrCheck(arr);

	for (int i = 0; i < vc.size(); i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
