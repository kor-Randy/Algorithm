#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int coin[101];
int N,K;
int arr[10001];

int dp()
{

	for (int i = 0; i < N; i++)
	{
		if (coin[i] > K)
			continue;
		//coin[i] = ����� ���� ����	
			for (int j = 1; j <= K; j++)
			{
				if (coin[i] > j)
					continue;
				
				arr[j] += arr[j - coin[i]];
				//���� ����ϴ� ���ΰ����� �� ����Ǽ��� ���Ѵ�
				//if coin[i]==5 �̰� j=10�̸�
				//arr[10]+=arr[5]���ٰ� 5¥�� ������
			}
		
	}

	return arr[K];

}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &coin[i]);
	}
	arr[0] = 1;


	printf("%d", dp());



	return 0;
}
