#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

int L;
int arr[10];
int check[10];
int cnt;
vector<int> vc[10] = { {0}, {1,3,4,5,7},{-1,1,2,3,4,5,7},{-1,2,3,1,5},{-3,-2,1,3,4,-1,5},{-4,-3,-2,-1,1,2,3,4},
{-4,-3,-1,2,3,-5,1},{-3,-2,1,-5,-1},{-4,-3,-2,-1,1,-7,-5},{-4,-3,-1,-7,-5} };

void bfs()
{
	queue<int> q;
	q.push(arr[1]);
	cnt = 2;
	
	while (1)
	{
		int now = q.front();
		q.pop();
		check[now] = 2;
		
		
		int next = arr[cnt];
		
		if (cnt > L)
			break;

		for (int i = 0; i < vc[now].size(); i++)
		{
			//printf("now = %d , next = %d , check[now] = %d , check[next] = %d\n", now, next, check[now], check[next]);

			if (now + vc[now][i] == next && check[next] == 1)
			{
			//	printf("갈수있음");
				check[next] = 2;
				q.push(next);
				cnt++;
			}
			else if (now == 1 && next == 7 && check[next] == 1 && check[4] == 2)
			{
				q.push(4);
			}
			else if (now == 2 && next == 8 && check[next] == 1 && check[5] == 2)
			{
				q.push(5);
			}
			else if (now == 3 && next == 9 && check[next] == 1 && check[6] == 2)
			{
				q.push(6);
			}
			else if (now == 1 && next == 3 && check[next] == 1 && check[2] == 2)
			{
				q.push(2);
			}
			else if (now == 4 && next == 6 && check[next] == 1 && check[5] == 2)
			{
				q.push(5);
			}
			else if (now == 7 && next == 9 && check[next] == 1 && check[8] == 2)
			{
				q.push(8);
			}
			else if (now == 1 && next == 9 && check[next] == 1 && check[5] == 2)
			{
				q.push(5);
			}
			else if (now == 3 && next == 7 && check[next] == 1 && check[5] == 2)
			{
				q.push(5);
			}
			else if (now == 7 && next == 1 && check[next] == 1 && check[4] == 2)
			{
				q.push(4);
			}
			else if (now == 8 && next == 2 && check[next] == 1 && check[5] == 2)
			{
				q.push(5);
			}
			else if (now == 9 && next == 3 && check[next] == 1 && check[6] == 2)
			{
				q.push(6);
			}
			else if (now == 3 && next == 1 && check[next] == 1 && check[2] == 2)
			{
				q.push(2);
			}
			else if (now == 6 && next == 4 && check[next] == 1 && check[5] == 2)
			{
				//printf("64");
				q.push(5);
			}
			else if (now == 9 && next == 7 && check[next] == 1 && check[8] == 2)
			{
				q.push(8);
			}
			else if (now == 9 && next == 1 && check[next] == 1 && check[5] == 2)
			{
				q.push(5);
			}
			else if (now == 7 && next == 3 && check[next] == 1 && check[5] == 2)
			{
				q.push(5);
			}

		}
		if (q.empty())
			break;

	}
}

void bfs2()
{

}

int main()
{
	scanf("%d", &L);
	
	for (int i = 1; i <= L; i++)
	{
		scanf("%d", &arr[i]);
		if (check[arr[i]] == 1)
		{
			printf("NO");
			return 0;
		}
		else
			check[arr[i]] = 1;
	}

	bfs();

	int res=0;

	for (int i = 1; i < 10; i++)
	{
		if (check[i] == 1)
			res++;
		
	}
	
	if (res > 0)
		printf("NO");
	else
		printf("YES");
	return 0;
}
