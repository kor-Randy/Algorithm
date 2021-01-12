#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int arr[101];
int visit[10001];

void dp()
{
	
	for (int i = 0; i < N; i++)
	{
		int coin = arr[i];
		for (int j = 1; j <= K; j++)
		{

			if (coin > j)
				continue;
			else
			{
				visit[j] = min(visit[j], visit[j - coin] + 1);
			}
		}
	}

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= K; i++)
	{

		visit[i] = 100000;
	}
	dp();
	if (visit[K] != 100000)
		cout << visit[K];
	else
		cout << -1;

	return 0;
}
