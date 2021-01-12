#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int N, M;
int arr[101][101];
vector<pair<int,int>> vv;
int v[101];
vector<int> vc[101];
int res, temp;
int start;
void dfs(int n, int cnt)
{
	
	if (start == n)
		arr[n][n] = 0;//�ڱ� �ڽ��� ��� 0���� 
	
		for (int i = 0; i < vc[n].size(); i++)
		{
			int now = vc[n][i];//�ڽŰ� ����� ��� Ȯ��
			if (arr[start][now] <= cnt + 1)
			{
				//������ ����� ������ ���簪�� ũ�� ����
				continue;
			}
			else
			{
				//������ ����� ������ ���簪�� ������ 
				//���� �ٲٰ�
				//now�� ģ���� Ȯ��
				arr[start][now] = min(arr[start][now], cnt + 1);
				dfs(now, cnt + 1);
			}
		}
	

}

int main()
{
	scanf("%d %d", &N,&M);

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vc[a].push_back(b);
		vc[b].push_back(a);
	}//����� ����
	

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = 10000;
		}
	}//�Ÿ��� �ʱ�ȭ

	for (int i = 1; i <= N; i++)
	{
		start = i;
		dfs(i, 0);
	}//���� ����� ���� dfs ����Ž��

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		for (int j = 1; j <= N; j++)
		{
			temp += arr[i][j];
		}
		vv.push_back({temp,i});
	}//���� ����� ���� �ٸ� �������� �ɺ����� �� ��ħ

	sort(vv.begin(), vv.end());

	printf("%d\n", vv[0].second);

	return 0;
}
