#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
vector<vector<int>> vc;
int res, cnt, temp;
int visit[1001];
bool cmp(vector<int> a, vector<int> b)
{
	return a[2] < b[2];
}

int find(int n)
{
	if (visit[n] == n)
		return n;
	else
	{
		return find(visit[n]);
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	if (N == 1)
	{
		printf("0");
		return 0;
	}

	for (int i = 0; i < M; i++)
	{
		vector<int> v;
		int a, b,c;
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);
		vc.push_back(v);
	}

	for (int i = 1; i <= N; i++)
	{
		visit[i] = i;
	}

	sort(vc.begin(), vc.end(), cmp);

	for (int i = 0; i < vc.size(); i++)
	{
		int now = vc[i][0];
		int next = vc[i][1];
		int d = vc[i][2];

		if (find(now) == find(next))
			continue;
		else
		{
			res += d;
			visit[find(next)] = now;
			N--;
		}

		if (N == 0)
			break;

	}

	printf("%d", res);


	return 0;
}
