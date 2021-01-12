#include<stdio.h>
#include<iostream>
#include<algorithm>
//#include<unordered_map>
using namespace std;

//unordered_map<int, int> um;

int a[500001];
int N, M;
int main()
{

	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		//um[a[i]]++;
	}
	sort(&a[0], &a[N]);
	cin >> M;

	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);

		printf("%d ", upper_bound(&a[0], &a[N], num)-lower_bound(&a[0],&a[N],num));

		//printf("%d ", um[num]);
	}

	return 0;
}
