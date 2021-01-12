#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;
int arr[51][2];
int temp, cnt, res;
vector<int> vc1, vc2;
int six;
int one[6];
int greedy()
{
	if (vc1[0] > vc2[0] * 6)
		six = vc2[0] * 6;
	else
	{
		six = vc1[0];
	}

	cnt = N;

	while (1)
	{
		
		if (cnt >= 6)
		{
			res += six;
			cnt -= 6;
		}
		else
		{
			switch (cnt)
			{
				case 1: 
				{
					if (vc1[0] < vc2[0])
						res += vc1[0];
					else
					{
						res += vc2[0];
					}
					cnt -= 1;
					break;
				}
				case 2:
				{
					if (vc1[0] < vc2[0]*2)
						res += vc1[0];
					else
					{
						res += vc2[0]*2;
					}
					cnt -= 2;
					break;
				}
				case 3:
				{
					if (vc1[0] < vc2[0]*3)
						res += vc1[0];
					else
					{
						res += vc2[0]*3;
					}
					cnt -= 3;
					break;
				}
				case 4:
				{
					if (vc1[0] < vc2[0]*4)
						res += vc1[0];
					else
					{
						res += vc2[0]*4;
					}
					cnt -= 4;
					break;
				}
				case 5:
				{
					if (vc1[0] < vc2[0]*5)
						res += vc1[0];
					else
					{
						res += vc2[0]*5;
					}
					cnt -= 5;
					break;
				}
			}
		}

		if (cnt == 0)
			break;

	}

	return res;

}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &arr[i][0], &arr[i][1]);
		vc1.push_back(arr[i][0]);
		vc2.push_back(arr[i][1]);
	}
		
	sort(vc1.begin(), vc1.end());
	sort(vc2.begin(), vc2.end());
	
	printf("%d", greedy());

	return 0;
}
