#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int T, N, M;
priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int, int>>> pq;
queue<pair<int, int>> q;

int brute()
{
	
	int cnt=1;

	while(q.size()>0)
	{
		pair<int, int> pqnow = pq.top();

		pair<int, int> qnow = q.front();
		q.pop();

		

		if (qnow.first == pqnow.first)
		{
			if (qnow.second == M)
			{
				
				return cnt;
			}
			else
			{
				pq.pop();
				cnt++;
			}
				
		}
		else
		{
			q.push({ qnow.first,qnow.second });
			
		}
	}

}

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d", &N, &M);
		for (int j = 0; j < N; j++)
		{
			int temp;
			scanf("%d", &temp);
			pq.push({temp, j});
			q.push({ temp,j });

			
		}


		

		printf("%d\n", brute());

		while (pq.size() > 0)
		{
			pq.pop();
		}
		while(q.size() > 0)
		{
			q.pop();
		}
		
	}

	



	return 0;
}
