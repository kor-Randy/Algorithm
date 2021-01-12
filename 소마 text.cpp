#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, K;
int arr[100001];
int visit[100001];
int mi, res, temp, cnt;

void dfs(int l, int r)
{

	for (int i = 1; i <= K; i++)
	{
		


	}

}


int main()
{
	scanf("%d %d", &N, &K);
	temp = 100001;
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &arr[i]);
		if (temp > arr[i]) {
			mi = i;
			temp = arr[i];
		}
	}
	temp = K;
	res = 1;
	while (1)
	{
		//printf("mi : %d , temp : %d , res : %d\n", mi, temp, res);
		if (mi <= temp)
		{
			cnt = N - temp;

			if ((double)cnt / (double)(K - 1) == cnt / (K - 1))
			{
				res += cnt / (K - 1);
			}
			else
			{
				res += cnt / (K - 1) + 1;
			}
			break;

		}
		else
		{
			temp += K - 1;
			res++;
		}
	}

	printf("%d", res);



	return 0;
}
