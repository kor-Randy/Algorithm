#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[41];
int d[41];
int res, cnt, temp;

void dp()
{
	res = 1;
	temp = 1;
	
	d[0] = 1;
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= N; i++)
	{
		d[i] = d[i - 1] + d[i - 2];
	}

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int a;
		scanf("%d", &a);
		arr[a-1] = 1;
	}

	if (N == 1)
	{
		res = 1;
		
		printf("%d", res);
	}
	else
	{
		dp();
		temp = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[i] == 1)
			{
				//printf("i : %d , temp : %d\n", i, temp);
				res *= d[temp];
				temp = 0;
			}
			else if (i == N - 1)
			{
				temp++;
				res *= d[temp];
			}
			else
			{
				temp++;
			}
		}
		printf("%d", res);
	}

	return 0;
}
