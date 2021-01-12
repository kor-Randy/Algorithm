#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int T[16];
int P[16];
int arr[16];

int dp(int n)
{
	
	if (n == 1)
		return arr[n] = P[n];
	else if (arr[n] != 0)
		return arr[n];
	else
	{
		
		for (int i = n - 1; i > 0; i--)
		{
			if (i + T[i] <= n)
			{
				//���� �� �� ����
				arr[n] = max(arr[n], dp(i) + P[n]);
			}
			else
			{
				//���� �� �� ������ (���� ���ϴ°�, ���±��� �� �Ѱ��� max) �� max�� ��´�
				arr[n] = max(dp(i), P[n]);
			}
		}
		printf("n : %d, arr[n] : %d\n", n, arr[n]);
		return arr[n];
	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &T[i], &P[i]);
	}

	printf("%d", dp(N));

	return 0;
}
