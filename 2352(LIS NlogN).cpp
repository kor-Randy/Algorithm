#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int arr[40001];
vector<int> vc;
int res;
void lis()
{
	vc.push_back(arr[0]);
	for (int i = 1; i < N; i++)
	{
		if (vc.back() < arr[i])
		{
			vc.push_back(arr[i]);
		}
		else
		{
			auto it = lower_bound(vc.begin(), vc.end(), arr[i]);
			*it = arr[i];
		}
	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	lis();
	
	
	
	printf("%d", vc.size());

	return 0;
}
