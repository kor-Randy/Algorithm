#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[100001][3];
int ta[3], ti[3];
int ma[3];
int mi[3];
int N;
int res, temp, cnt;

void dp(int n)
{
	
	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{

			mi[0] = arr[i][0];
			mi[1] =arr[i][1];
			mi[2] = arr[i][2];

			ma[0] = arr[i][0];
			ma[1] =  arr[i][1];
			ma[2] =  arr[i][2];
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				ti[j] = mi[j];
				ta[j] = ma[j];
			}

			mi[0] = min(ti[0], ti[1]) + arr[i][0];
			mi[1] = min(min(ti[0], ti[1]),ti[2]) + arr[i][1];
			mi[2] = min(ti[1], ti[2]) + arr[i][2];

			ma[0] = max(ta[0], ta[1]) + arr[i][0];
			ma[1] = max(max(ta[0], ta[1]), ta[2]) + arr[i][1];
			ma[2] = max(ta[1], ta[2]) + arr[i][2];
		}

		
	}

}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}


	int a, b;
	dp(N - 1);
	a = max(max(ma[0], ma[1]), ma[2]);
	b = min(min(mi[0], mi[1]), mi[2]);

	printf("%d %d", a, b);

	return 0;
}
