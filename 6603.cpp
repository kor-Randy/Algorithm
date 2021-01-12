#include<stdio.h>
#include<iostream>
using namespace std;

int k;
int S[14];
int pick[6];
int check[14];

void find(int cnt,int index)
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			printf("%d ", pick[i]);
		}
		printf("\n");
		return;

	}
	
	for (int i = index; i < k; i++)
	{
		if (check[i] == 0)
		{
			pick[cnt] = S[i];
			check[i] = 1;
			cnt++;
			find(cnt,i);
			check[i] = 0;
			cnt--;
		}
	}
}

int main()
{
	
	while (1)
	{
		scanf("%d", &k);
		
		if (k == 0)
			break;
		else
		{
			for (int i = 0; i < k; i++)
			{
				int temp;
				scanf("%d", &temp);
				S[i] = temp;
			}


			find(0,0);
			printf("\n");

		}
	}

	return 0;
}
