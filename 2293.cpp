#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int arr[101];
int visit[10001];

void dp()
{
	visit[0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			int coin = arr[i];
			if (coin>j)
				continue;
			else
			{
				visit[j] += visit[j - coin];
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
		cin >> arr[i];

	dp();

	cout << visit[K];

	return 0;
}
