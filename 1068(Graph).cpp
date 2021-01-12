#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N,d;
int res, temp;
int arr[51];
int cnt[51];

int find(int n)
{
	if (arr[n] == -2)//내 부모가 사라졌으면 -2 리턴
		return -2;
	else if (arr[n] == -1)//루트에 도착했으면 0 리턴
		return 0;
	else
	{
		return find(arr[n]);//내 부모의 부모를 찾는다 (재귀)
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &d);

	arr[d] = -2;

	for (int i = 0; i < N; i++)
	{
		if (find(i) == -2)
		{
			//부모까지 가는 중에 삭제할 노드가 있음
			//자신도 사라짐
			arr[i] = -2;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if(arr[i]!=-1)
			cnt[arr[i]]++;
		//i번째 노드가 참조하는 노드의 cnt[arr[i]]++;
	}

	for (int i = 0; i < N; i++)
	{
		if (cnt[i] == 0 && arr[i] != -2)
			res++;
		//i번째가 한번도 참조되지 않고 -2가 아닌(사라지지 않은) 노드들의 갯수 확인
	}
	printf("%d", res);


	return 0;
}
