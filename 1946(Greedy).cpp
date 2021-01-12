#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
/*
	7
3 6
7 3
4 2
1 4
5 7
2 5
6 1

1. 서류심사를 오름차순대로 정렬
1 4
2 5
3 6
4 2
5 7
6 1
7 3

2. 면접성적을 차례대로 비교
1 4 <- 다음에 올 사람은 면접성적이 4위보다 좋아야 함 (count : 1)
2 5 <- Pass
3 6 <- Pass
4 2 <- 다음에 올 사람은 면접성적이 2위보다 좋아야 함 (count : 2)
5 7 <- Pass
6 1 <- 다음에 올 사람은 면접성적이 1위보다 좋아야 함 / 불가능 (count : 3)
7 3 <- Break
*/
int T, N;
int arr[100001][3];
vector<pair<int, pair<int, int>>> vc;
vector<int> vc1;
vector<int> zz;
int first[2], second[2];
int res;
bool compare1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.second.first < b.second.first;
	
}

bool compare2(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.second.second < b.second.second;
	
}

int main()
{
	scanf("%d", &T);
	
	for (int k = 0; k < T; k++)
	{
		zz.push_back(0);
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			if (a == 1)
			{
				first[0] = i;
				first[1] = b;
			}
			else if (b == 1)
			{
				second[0] = i;
				second[1] = a;
			}
			
				vc.push_back({ i,{ a,b } });
			
			
				
		}


		sort(vc.begin(), vc.end(), compare1);
		int m = first[1];
		for (int i = 0; i < vc.size(); i++)
		{
			if (vc[i].second.second <= m)
			{
				res++;
				m = vc[i].second.second;
			}
			else
				continue;
			

		}

		

		
		printf("%d\n", res);
		vc.clear();
		vc1.clear();
		res = 0;
	}
	



	

	


	return 0;
}
