#include<stdio.h>
#include<iostream>
using namespace std;

int arr[4];
int M;
int now;
int ch[51][2];
int simul()
{
	
	now = 1;

	for (int i = 0; i < M; i++)
	{
		if (ch[i][0] == now)
		{
			now = ch[i][1];
		}
		else if (ch[i][1] == now)
		{
			now = ch[i][0];
		}
	}

	return now;

}

int main()
{
	scanf("%d", &M);

	for (int i = 0; i < M; i++)
	{
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		ch[i][0] = t1;
		ch[i][1] = t2;
	}

	printf("%d", simul());
	return 0;
}
