#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int N;
int arr[100][10];
int temp, cnt, res;
int a, b;
void dp()
{
	res = 9;
	for (int i = 2; i < 11; i++)
	{
		//자릿수
		for (int j = 1; j < 10; j++)
		{
			//첫자리 숫자
			for (int k = 0; k < j; k++)
			{
				//첫자리보다 작은 숫자들

				arr[i][j] += arr[i - 1][k];

			}
			res += arr[i][j];

			if (res >= N)
			{
				a = i;
				b = j;
				return;
			}

		}
	}

}

int main()
{
	scanf("%d", &N);

	if (N <10)
	{
		printf("%d",N);
		return 0;
	}
	else if (N >= 1023)
	{
		printf("-1");
		return 0;
	}

	for (int i = 0; i < 10; i++)
	{
		arr[1][i] = 1;
	}
	dp();



	unsigned long long num = b*pow(10, a - 1);

	//printf("num : %llu", num);

	while (1)
	{
		unsigned long long temp = num;
		bool flag = true;
		int past = temp % 10;
		temp /= 10;
		while (temp != 0)
		{
			if (past >= temp % 10)
			{
				flag = false;
				break;
			}

			past = temp % 10;
			temp /= 10;
		}

		if (flag == true)
		{
			res++;
		}

		if (res == N)
		{
			printf("%llu", num);
			return 0;
		}

		num++;

	}


	return 0;
}
