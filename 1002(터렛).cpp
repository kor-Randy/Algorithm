#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int x_1, y_1, r_1, x_2, y_2, r_2;
int T;
int res, cnt, temp;
vector<pair<int, int>> vc1, vc2;

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d %d %d %d", &x_1, &y_1, &r_1, &x_2, &y_2, &r_2);
		int d = abs(x_1 - x_2) + abs(y_1 - y_2);
		int dr = abs(r_1 + r_2);
		
		if (d == abs(r_1 + r_2))//�߽� ���� �Ÿ� == ������ ��(����)
			printf("1\n");
		else if (d == 0 && r_1 - r_2 == 0) // �߽��� ���� �������� ����
			printf("-1\n");
		else if (d == abs(r_1 - r_2) && d != 0 && d < abs(r_1 + r_2))//�߽ɻ��� �Ÿ� < ������ ��
		{
			printf("1\n");
		}
		else if (d < abs(r_1 - r_2))
		{
			//�� �ȿ� �ٸ� ���� ������
			printf("0\n");
		}
		else if (d < abs(r_1 + r_2))
		{
			//�� ���� �� ������ ����
			printf("2\n");
		
		}
		else if (d > abs(r_1 + r_2))//�߽ɻ��� �Ÿ� > ������ ��
			printf("0\n");
			
		
		


	}
	return 0;
}
