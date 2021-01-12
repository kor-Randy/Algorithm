#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
int arr[100001];
int start, last;
int temp, cnt, res;
int check[100001][2];
int dp()
{
	int one, minus;
	
	if (arr[start] == 1)
	{
		one = check[last][0] - check[start][0] + 1;
		minus = check[last][1] - check[start][1];
	}
	else
	{			
		one = check[last][0] - check[start][0];
		minus = check[last][1] - check[start][1] + 1;		
	}

	return min(one, minus) * 2;
	

}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] == 1)
		{
			a++;
		}
		else
		{
			b++;
		}
		check[i][0] = a;
		check[i][1] = b;//1 ~ i 까지의 1과 -1 갯수를 적음
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &start, &last);
		if (start == last)
			printf("0\n");
		else
		{
			printf("%d\n", dp());
		}

	}


	return 0;
}
