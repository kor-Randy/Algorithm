#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N, K;
int arr[10001];
long long res;
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> K >> N;

	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
	}

	long long left = 0;
	long long right = pow(2,31);

	while (1)
	{
		long long middle = (left + right) / 2;

		if (middle == left)
		{
			long long l = 0, r = 0;
			for (int i = 0; i < K; i++)
			{
				l += (arr[i] / left);
				r += (arr[i] / right);
			}

			if (r >= N)
				res = right;
			else
				res = left;
			break;
		}


		long long cnt = 0;
		for (int i = 0; i < K; i++)
		{
			cnt += (arr[i] / middle);
		}

		if (cnt >= N)
		{
			left = middle;
		}
		else
		{
			right = middle;
		}

	}

	cout << res;

	return 0;
}
