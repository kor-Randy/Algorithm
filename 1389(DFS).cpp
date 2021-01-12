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
		arr[n][n] = 0;//자기 자신일 경우 0으로 
	
		for (int i = 0; i < vc[n].size(); i++)
		{
			int now = vc[n][i];//자신과 연결된 사람 확인
			if (arr[start][now] <= cnt + 1)
			{
				//이전에 저장된 값보다 현재값이 크면 무시
				continue;
			}
			else
			{
				//이전에 저장된 값보다 현재값이 작으면 
				//값을 바꾸고
				//now의 친구도 확인
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
	}//양방향 연결
	

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			arr[i][j] = 10000;
		}
	}//거리값 초기화

	for (int i = 1; i <= N; i++)
	{
		start = i;
		dfs(i, 0);
	}//각각 사람에 대해 dfs 완전탐색

	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		for (int j = 1; j <= N; j++)
		{
			temp += arr[i][j];
		}
		vv.push_back({temp,i});
	}//각각 사람에 대해 다른 사람들과의 케빈베이컨 값 합침

	sort(vv.begin(), vv.end());

	printf("%d\n", vv[0].second);

	return 0;
}
