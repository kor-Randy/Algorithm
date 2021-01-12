#include<stdio.h>
#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

#define MAX pow(2,31)-1

int N;
priority_queue<pair<int,int>> pq;
int cnt;
vector<int> vc;

void greedy()
{
	int now = 0;
	int start=0;
	int end=0;
	while (1)
	{
		
		start = -pq.top().second;
		end = -pq.top().first;
		
		
		
		
		if (start >= now && end<=MAX)
		{
			now = end;
			cnt++;
			pq.pop();
		}
		else
		{
			pq.pop();
		}

		if (pq.empty())
			break;

	}


}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int t1, t2;
		scanf("%d %d", &t1,&t2);
		pq.push({-t2,-t1});
	}



	greedy();

	printf("%d", cnt);
	return 0;
}
