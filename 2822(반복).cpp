#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

pair<int,int> arr[8];
int res;
pair<int,int> temp[8];
vector<int> pick;
int main()
{
	for (int i = 0; i < 8; i++)
	{
		int t;
		scanf("%d", &t);
		arr[i] = { t,i };
		
	}

	sort(&arr[0], &arr[8]);

	for (int i = 7; i >2; i--)
	{
		res += arr[i].first;
		pick.push_back(arr[i].second);

	}

	sort(pick.begin(), pick.end());

	printf("%d\n", res);

	for (int i = 0; i < pick.size(); i++)
		printf("%d ", pick[i]+1);


	return 0;
}
