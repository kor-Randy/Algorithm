#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int N, M;
string str[1001];
int arr[4];
string res;
int temp;
int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}

	for (int i = 0; i < M; i++)
	{
		arr[0] = arr[1] = arr[2] = arr[3] = 0;
		for (int j = 0; j < N; j++)
		{
			if (str[j][i] == 'A')
			{
				arr[0]++;
			}
			else if (str[j][i] == 'C')
			{
				arr[1]++;
			}
			else if (str[j][i] == 'G')
			{
				arr[2]++;
			}
			else
			{
				arr[3]++;
			}
		}

		int ma = max(max(max(arr[0], arr[1]), arr[2]), arr[3]);
		
			if (arr[0] == ma)
			{
				res += 'A';
			}
			else if (arr[1] == ma)
			{
				res += 'C';

			}
			else if (arr[2] == ma)
			{
				res += 'G';

			}
			else
			{
				res += 'T';
			}
		
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (res[j] != str[i][j])
				temp++;
		}
	}

	cout << res<<"\n"<<temp;

	return 0;
}
