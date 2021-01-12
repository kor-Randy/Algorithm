#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int N;
queue<int> q;

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		q.push(i);
	}

	while (1)
	{
		if (q.size() == 1)
		{
			printf("%d", q.front());
			break;
		}
		else
		{
			q.pop();
			if (q.size() == 1)
			{
				printf("%d", q.front());
				break;
			}
			q.push(q.front());
			q.pop();
		}
	}

	return 0;
}
