#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int N, M,K;
int main()
{
	scanf("%d %d %d", &N, &M, &K);

	int a, b, c;
	int team = 0;
	a = N / 2;//����/2
	
	b = M;//����
	c = N + M; // ���л�
	team = min(a, b);//���� �� �ִ� ��ȸ �� ��
	int temp = c - team * 3;//���� ��� ��
	if(K<=temp)
	{
		printf("%d", team);
	}
	else
	{
		K -= temp;
		if ((double)K / 3 == K / 3)
		{
			//������ ������
			team -= K / 3;
		}
		else
		{
			team -= (K / 3) + 1;
		}
		printf("%d", team);
	}


	return 0;
}
