#include<stdio.h>
#include<iostream>
using namespace std;

int N, M;
int s,temp, res;
int arr[9];
int visit[9];
void tracking()
{

	if (s == M+1)
	{
		for (int i = 1; i <= M; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	else
	{
		for (int i = 1; i <= N; i++)
		{
			if (visit[i] == 0)
			{
				visit[i] = 1;
				arr[s++] = i;
				tracking();
				visit[i] = 0;
				s--;
			}
		}
	}

}

int main()
{
	scanf("%d %d", &N, &M);
	s = 1;
	tracking();

	return 0;
}
