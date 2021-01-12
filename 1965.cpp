#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int arr[1001];
vector<int> vc;
int visit[1001]; 
int res;
void lis()
{
	
	/* lower_bound를 사용해서 lis의 길이만 구하기
	
	vc.push_back(arr[0]);

	for (int i = 1; i < N; i++)
	{
		if (vc[vc.size() - 1] < arr[i])
		{
			vc.push_back(arr[i]);
		}
		else
		{
			auto index = lower_bound(vc.begin(), vc.end(), arr[i]);
			*index = arr[i];
		}
	}*/

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i])
			{
				visit[i] = max(visit[j]+1, visit[i]);
			}
		}
	}


}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		visit[i] = 1;
	}

	lis();
	sort(&visit[0], &visit[N]);
	cout << visit[N-1];

	return 0;
}
