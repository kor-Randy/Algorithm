#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int arr[51][51];
int d[14][101];
pair<int,int> dd[14];
int num[14];
int res;
vector<pair<int, int>> vc2;
vector<pair<int, int>> vc1;
int cnt, temp;

void select(int);
void cal();

void brute()
{

	for (int i = 0; i < vc2.size(); i++)
	{
		dd[i].second = i;
		for (int j = 0; j < vc1.size(); j++)
		{
			int a, b;
			a = vc2[i].first - vc1[j].first;
			b = vc2[i].second - vc1[j].second;
			if (a < 0)
				a = -a;
			if (b < 0)
				b = -b;
			d[i][j] = a + b;
			dd[i].first += d[i][j];
		}
	}
	res = 100000;
	select(0);

	printf("%d", res);

}

void select(int index)
{
	if (cnt == M)
	{
		cal();
		return;
	}
	else
	{
		for (int i = index; i < vc2.size(); i++)
		{

			//printf("num[cnt] ( cnt = %d) 에다가 i : %d 삽입\n", cnt, i);
			num[cnt] = i;
			cnt++;
			select(i+1);
			cnt--;

		}
	}
}

void cal()
{
	int a=0;
	
	for (int j = 0; j < vc1.size(); j++)
	{
		int tt = 10000;
		for (int i = 0; i < cnt; i++)
		{
			int n = num[i];

			tt = min(d[n][j], tt);

		}
		a += tt;
	}
//	printf("a : %d\n", a);
	res = min(res, a);

	//printf("    들의  결과값 : %d\n", res);
}

int main()
{	
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{

			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 2)
				vc2.push_back({ i,j });
			else if (arr[i][j] == 1)
				vc1.push_back({ i,j });
		}
	}

	brute();

	return 0;
}
