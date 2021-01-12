#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//N-100 과 자릿수를 비교한다. if 103이면 3회이고 1,0,3을 누르는 것도 3회
int N, M;
int arr[11];
int left, right;
int temp, cnt, res;
int flag,ss,a;

void check(int);

void brute()
{
	for (int i = 0; i <= 1000000; i++)
	{
		temp = i;
		flag = 0;
		check(temp);
		while (1)
		{
			
				
				for (int j = 0; j < M; j++)
				{
					if (temp % 10 == arr[j])
					{
						flag = 1; // 갈 수 없는 번호
						break;
					}
				}

				
				temp = temp / 10;

			if (temp == 0)
				break;

			
			

		}
		if (flag == 0)
		{

			if (N > i)
			{
				if ((N - i + cnt) < res)
					a = i;
				res = min(res, (N - i + cnt));

			}
			else if (N == i)
			{
				if (cnt < res)
					a = i;
				res = min(res, cnt);
				
			}
			else
			{
				if ((i - N + cnt) < res)
					a = i;
				res = min(res, (i - N + cnt));
			}

		}
		else
		{
			//printf("갈수 없음\n");
			
		}


	}

	//printf("a : %d\n", a);

}

void check(int b)
{
	if (b < 10)
		cnt = 1;
	else if (b < 100)
		cnt = 2;
	else if (b < 1000)
		cnt = 3;
	else if (b < 10000)
		cnt = 4;
	else if (b < 100000)
		cnt = 5;
	else
		cnt = 6;
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d", &arr[i]);
	}
	//여기서  자릿수 > '-' 눌러서 갈 수 있는 횟수 이면 '-'를 눌러서 간다.
	//N-100을 반환

	if (N < 10)
		ss = 1;
	else if (N < 100)
		ss = 2;
	else if (N < 1000)
		ss = 3;
	else if (N < 10000)
		ss = 4;
	else if (N < 100000)
		ss = 5;
	else
		ss = 6;

	if (ss < (N - 100) && N >= 100)
	{
		res = N - 100;
		brute();
		printf("%d", res);
	}
	else if (N < 100 && ss < (100 - N))
	{
		res = 100 - N;
		brute();
		printf("%d", res);
	}
	else if (N >= 100)
		printf("%d", (N - 100));
	else
		printf("%d", (100 - N));

	return 0;
}


