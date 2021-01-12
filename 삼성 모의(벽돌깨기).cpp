#include<iostream>

using namespace std;
int arr[100] = {0};


int fibo2(int n) {
	
	if (arr[n] != 0)
		return arr[n];
	else {
		return arr[n] = fibo2(n - 1) + fibo2(n - 2);
	}

}

int main() {

	int v;

	cin >> v;

	arr[1] = 1;
	arr[2] = 1;

	for (int i = 2; i <= v; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[v]<<", ";

	cout << fibo2(v);
	
	return 0;

}