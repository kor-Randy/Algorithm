#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
//N-100 �� �ڸ����� ���Ѵ�. if 103�̸� 3ȸ�̰� 1,0,3�� ������ �͵� 3ȸ
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
						flag = 1; // �� �� ���� ��ȣ
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
			//printf("���� ����\n");
			
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
	//���⼭  �ڸ��� > '-' ������ �� �� �ִ� Ƚ�� �̸� '-'�� ������ ����.
	//N-100�� ��ȯ

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


