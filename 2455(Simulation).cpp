#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int cnt;
int arr[4][2];
int res;

int simul()
{
	
	for (int i = 0; i < 4; i++)
	{
		cnt -= arr[i][0];
		res=max(res, cnt);
		cnt += arr[i][1];
		res=max(res, cnt);
	}
	return res;

}

int main()
{
	for (int i = 0; i < 4; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	printf("%d", simul());
	return 0;
}
