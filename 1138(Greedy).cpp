#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int res, cnt, temp;
int N;
int arr[11];

int d[11];

void greedy()
{

	for (int i = 1; i <= N; i++)
	{
		int num = arr[i];

		for (int j = 1; j <= N; j++)
		{
			if (num == 0 && d[j] == 0)
			{
				d[j] = i;
				break;
			}
			else if (d[j] == 0)
			{
				num--;
			}
		}


	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%d", &arr[i]);

	greedy();

	for (int i = 1; i <= N; i++)
		printf("%d ", d[i]);

	
	return  0;
}