#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int arr[1001];
int s[1001];
int res;
int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(&arr[0], &arr[N]);
	
	if (arr[0] != 1)
	{
		cout << '1';
		return 0;
	}
	s[0] = 1;
	for (int i = 1; i < N; i++)
	{
		
			if (s[i - 1] + 1 < arr[i])
			{
				res = s[i - 1] + 1;
				break;
			}
			else
			{
				s[i] = s[i - 1] + arr[i];
			}
		
	}
	if (res != 0)
		cout << res;
	else
		cout << s[N - 1] + 1;

	return 0;
}
