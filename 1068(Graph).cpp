#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N,d;
int res, temp;
int arr[51];
int cnt[51];

int find(int n)
{
	if (arr[n] == -2)//�� �θ� ��������� -2 ����
		return -2;
	else if (arr[n] == -1)//��Ʈ�� ���������� 0 ����
		return 0;
	else
	{
		return find(arr[n]);//�� �θ��� �θ� ã�´� (���)
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &d);

	arr[d] = -2;

	for (int i = 0; i < N; i++)
	{
		if (find(i) == -2)
		{
			//�θ���� ���� �߿� ������ ��尡 ����
			//�ڽŵ� �����
			arr[i] = -2;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if(arr[i]!=-1)
			cnt[arr[i]]++;
		//i��° ��尡 �����ϴ� ����� cnt[arr[i]]++;
	}

	for (int i = 0; i < N; i++)
	{
		if (cnt[i] == 0 && arr[i] != -2)
			res++;
		//i��°�� �ѹ��� �������� �ʰ� -2�� �ƴ�(������� ����) ������ ���� Ȯ��
	}
	printf("%d", res);


	return 0;
}
