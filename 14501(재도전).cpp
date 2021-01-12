#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N;
int T[16];
int P[16];
int temp, res, cnt;

int d[17];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &T[i], &P[i]);
	}

	if(T[1]+1 <= N+1)
		d[1] = P[1];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (T[j] + j <= i)
			{
				//상담을 받을 수 있다면
				if (T[i] + i > N+1)
				{
					//N일내로 i번째 일을 못끝냄
					d[i] = max(d[i], d[j]);
				}
				else
					d[i] = max(d[i], d[j] + P[i]);
			}
			else
			{
				if (T[i] + i <= N+1)
				{
					//N일내로 i번째 일을 끝냄
					d[i] = max(d[i], P[i]);
				}
				
			}
		}
		//printf("i : %d , d[i] : %d\n", i, d[i]);
	}

	sort(&d[1], &d[N+1]);
	printf("%d", d[N]);

	return 0;
}
