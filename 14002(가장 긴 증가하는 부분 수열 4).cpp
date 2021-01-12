#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int arr[1001];
vector<int> vc[1001];

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
	
		cin >> arr[i];
		vc[i].push_back(arr[i]);
	}

	for (int i = 0; i < N; i++) {
	
		for (int j = 0; j < i; j++) {
		
			if (arr[i] > arr[j]) {
				
				if (vc[i].size() < vc[j].size() + 1) {
				
					vc[i] = vc[j];
					vc[i].push_back(arr[i]);
				
				}

			}

		}
	
	}
	int index = 0;
	int ma = vc[0].size();
	for (int i = 1; i < N; i++) {
		if (ma < vc[i].size()) {
			ma = vc[i].size();
			index = i;
		}
	}

	printf("%d\n", vc[index].size());

	for (int i = 0; i < vc[index].size(); i++) {
	
		printf("%d ", vc[index][i]);

	}

	return 0;
}
