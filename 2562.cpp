#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

pair<int, int> arr[10];

int main()
{
	for (int i = 0; i < 9; i++)
	{
		int a;
		scanf("%d", &a);
		arr[i] = { a,i };
	}
	sort(&arr[0], &arr[9]);

	printf("%d\n%d", arr[8].first,arr[8].second+1);

	return 0;
}
