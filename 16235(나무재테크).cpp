#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, K, M;
int a[11][11];
int arr[11][11];//���
vector<int> tree[11][11];//����(����,����)
vector<int> temp;
vector<int> summer[11][11];
int xx[8] = { -1,-1,-1,0,0,1,1,1 };
int yy[8] = { -1,0,1,-1,1,-1,0,1 };

void spring()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sort(tree[i][j].begin(), tree[i][j].end());

			for(int k = 0 ; k < tree[i][j].size(); k++)
			{
				int now = tree[i][j][k];
				if (arr[i][j] >= now)
				{
					//���̸�ŭ ���� ����� �ִ�
					//����++
					//�ٽ� �ִ´�
					arr[i][j] -= now;
					now++;
					//temp�� �־�ΰ� �������� �� �ִ´�.
					temp.push_back(now);

				}
				else
				{
					summer[i][j].push_back(now);
				}

			}
			//temp�� �ִ� �͵� tree[i][j]�� �־����
			tree[i][j].clear();
			tree[i][j].swap(temp);
			
		}
	}
}

void summ()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for(int k=0;k<summer[i][j].size();k++)
			{

				int age = summer[i][j][k];
				if (age < 2)
					continue;
				int waste = age / 2;

				arr[i][j] += waste;

			}
			summer[i][j].clear();
		}
	}
		

	
}

void fall()
{
	vector<int> qq;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{

			for (int k = 0; k < tree[i][j].size(); k++) 
			{
				int now = tree[i][j][k];

				if (now % 5 == 0)
				{
					for (int l = 0; l < 8; l++)
					{
						int nx = i + xx[l];
						int ny = j + yy[l];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N)
							continue;
						else
						{
							//�ֺ��� 1¥�� ���� ����
							tree[nx][ny].push_back(1);
						}

					}
				}

			}

		}
	}
}

void winter()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] += a[i][j];
		}
	}
}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			arr[i][j] = 5;
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		tree[a-1][b-1].push_back(c);

	}

	for (int i = 0; i < K; i++)
	{
		spring();
		summ();
		fall();
		winter();
	}
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			res += tree[i][j].size();
		}
	}

	cout << res;
	return 0;
}
