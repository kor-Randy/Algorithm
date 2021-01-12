#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,X;
int arr[10001];
vector<int> vc;
int res, cnt;
int main()
{
	scanf("%d %d", &N,&X);

	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	for (int i = 0; i < N; i++)
	{
		if (X > arr[i])
			vc.push_back(arr[i]);
	}

	for (int i = 0; i < vc.size(); i++)
	{
		printf("%d ", vc[i]);
	}

	return 0;
}
