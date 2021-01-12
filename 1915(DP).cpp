#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<stdlib.h>
using namespace std;

int N, M;
int arr[1001][1001];
int res, cnt, temp;

void dp()
{
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == 0 || j == 0)
			{
				res = max(arr[i][j], res);
			}
			else if (arr[i][j] == 1)
			{
				arr[i][j] = min(min(arr[i - 1][j - 1], arr[i - 1][j]), arr[i][j - 1]) + 1;
				res = max(res, arr[i][j]);
			}
		}
	}

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
			arr[i][j] = str[j] - '0';
	}
	dp();
	printf("%d", res * res);
	


	return 0;
}
