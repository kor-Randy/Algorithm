#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,M;
int num[12];
int arr[4];
int res, temp, cnt;
int mi, ma;
vector<int> vc;
void simul()
{
	do 
	{
		temp = 0;
		for (int i = 0; i < N; i++)
		{
			

			if (i == 0)
			{
				temp = num[0];
			}
			else
			{
				int j = i - 1;
				if (vc[j] == 0)
				{
					//µ¡¼À
					temp += num[i];
				}
				else if (vc[j] == 1)
				{
					//»¬¼À
					temp -= num[i];
				}
				else if (vc[j] == 2)
				{
					//°ö¼À
					temp *= num[i];
				}
				else
				{
					//³ª´°¼À
					temp /= num[i];
				}
			}
		}
		ma = max(ma, temp);
		mi = min(mi, temp);
		//printf("temp : %d\n", temp);

	} while (next_permutation(vc.begin(), vc.end()));

}

int main()
{
	scanf("%d", &N);
	M = N - 1;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}
	int a, b, c, d;
	scanf("%d %d %d %d", &a,&b,&c,&d);
	for (int i = 0; i < a; i++)
		vc.push_back(0);
	for (int i = 0; i < b; i++)
		vc.push_back(1);
	for (int i = 0; i < c; i++)
		vc.push_back(2);
	for (int i = 0; i < d; i++)
		vc.push_back(3);

	ma = -2100000000;
	mi = 2100000000;

	simul();
	printf("%d\n%d", ma, mi);
	

	return 0;
}
