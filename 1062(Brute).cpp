#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int N, K;

string str[51];
int arr[26];
int visit[26];
int res, cnt;

void check()
{
	cnt = 0;
	
	for (int i = 0; i < N; i++)
	{
		bool flag = true;
		if (str[i].size() > 8)
		{
			//���̰� 8 �ʰ�
			for (int j = 4; j <= str[i].size() - 5; j++)
			{
				//�� ���� 
				//printf("���� : %c , index : %d visit : %d\n", str[i][j], str[i][j] - 'a',visit[str[i][j] - 'a']);
				if (visit[str[i][j] - 'a'] != 1)
				{
					//printf("���ڰ� �Ȼ����ִ�\n");
					flag = false;
					break;
				}
			}
			if (flag == false)
				continue;//���� �ܾ� Ȯ��
			else
			{
				//printf("�ܾ� ����\n");
				//�� �ܾ� ����
				cnt++;
			}

		}
		else
		{
			cnt++;
		}

	}

	

}

void com(int c, int index)
{
	if (c >= K)
	{
		//printf("�˻�\n");
		//�˻�
		check();
		res = max(res,cnt );
		return;
	}

	for (int i = index; i < 26; i++)
	{
		if (i == 'a' - 'a' || i == 'c' - 'a' || i == 'n' - 'a' || i == 't' - 'a' || i == 'i' - 'a')
			continue;
		else
		{
			//printf("%c �߰�\n", (i + 'a'));

			visit[i] = 1;
			//printf("index : %d , visit : %d\n",i+'a', visit[i + 'a']);

			com(c + 1, i + 1);

			visit[i] = 0;
		}
	}

}

int main()
{
	scanf("%d %d", &N, &K);

	visit['a' - 'a'] = visit['c' - 'a'] = visit['n' - 'a'] = visit['t' - 'a'] = visit['i' - 'a'] = 1;


	for (int i = 0; i < N; i++)
	{
		cin >> str[i];
	}

	
	if (K == 26)
	{
		printf("%d", N);
	}
	else if (K < 5)
	{
		
		printf("0");
	}
	else
	{
		com(5, 0);
		printf("%d", res);
	}

	return 0;
}
