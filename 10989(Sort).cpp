#include<stdio.h>
#include<iostream>
using namespace std;

short arr[10001];
int N;
int main()
{

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		short temp;
		scanf("%hd", &temp);
		arr[temp]++;
	}

	

	for (int i = 1; i < 10001; i++)
	{
		while (arr[i] > 0)
		{
			printf("%hd\n", i);
			arr[i]--;
		}
	}

	return 0;
}
