#include<stdio.h>
#include<algorithm>
using namespace std;

int N, M;
int arr[101];

int brute()
{
	int res,temp;
	res =temp= 0;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				temp = arr[i] + arr[j] + arr[k];
				if (temp <= M)
				{
					res = max(res, temp);
				}
			}
		}
	}
	return res;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("%d", brute());

	return 0;
}