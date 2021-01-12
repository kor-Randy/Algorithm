#include<stdio.h>
#include<iostream>

using namespace std;

int T,N;
int arr[41];
pair<int,int> temp[41];
pair<int,int> fibonacci(int n) {
	if (n == 0) {
		return temp[0] = make_pair(1,0);
		
	}
	else if (n == 1) {
		return temp[1] = make_pair(0, 1);
	}
	else if (temp[n].first != 0 || temp[n].second != 0)
	{
		return temp[n];
	}
	else {
		pair<int, int> a[2];
		a[1] = fibonacci(n - 1);
		a[0] = fibonacci(n - 2);
		return temp[n] = make_pair(a[1].first+a[0].first, a[1].second + a[0].second);
	}
}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < N; i++)
	{
		temp[i] = make_pair(0, 0);
	}
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);

		


			pair<int, int> res = fibonacci(N);

			printf("%d %d\n", res.first, res.second);

		

	}
	



	return 0;
}