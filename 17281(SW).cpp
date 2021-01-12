#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;

int N;
int vc[9];
int arr[51][10];
int tmp[10];
int res, temp, cnt;
int base[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int a;
			cin >> a;
			arr[i][j] = a;
		}
		
	}

	for (int i = 1; i < 9; i++)
	{
		vc[i] = i;
	}
	do 
	{
		for (int i = 0; i < 9; i++)
		{
			if (i == 3)
			{
				tmp[i] = 0;
			}
			else if(i<3)
			{
				tmp[i] = vc[i+1];
			}
			else if (i > 3)
			{
				tmp[i] = vc[i];
			}
		}
		int index = 0;
		int score = 0;
		int r = 0;

		for (int i = 0; i < N; i++)
		{
			int o = 0;

			int inning = 0;
			//°¢ ÀÌ´×
			while (1)
			{
				r = arr[i][tmp[index++]];
				index %= 9;
				if (r == 0)
				{
					//¾Æ¿ô
					o++;
				}
				else
				{
					
					if (r == 1)
					{
						if (base[2] == 1)
						{
							inning++;
							base[2] = 0;
						}
						if (base[1] == 1)
						{
							base[2] = 1;
							base[1] = 0;
						}
						if (base[0] == 1)
						{
							base[1] = 1;
							base[0] = 0;
						}
						base[0] = 1;
					}
					else if (r == 2)
					{
						if (base[2] == 1)
						{
							inning++;
							base[2] = 0;
						}
						if (base[1] == 1)
						{
							inning++;
							base[1] = 0;
						}
						if (base[0] == 1)
						{
							base[2] = 1;
							base[0] = 0;
						}
						base[1] = 1;
					
					}
					else if (r == 3)
					{
						if (base[2] == 1)
						{
							inning++;
							base[2] = 0;
						}
						if (base[1] == 1)
						{
							inning++;
							base[1] = 0;
						}
						if (base[0] == 1)
						{
							inning++;
							base[0] = 0;
						}
						base[2] = 1;
					}
					else
					{
					
						if (base[2] == 1)
						{
							inning++;
							base[2] = 0;
						}
						if (base[1] == 1)
						{
							inning++;
							base[1] = 0;
						}
						if (base[0] == 1)
						{
							inning++;
							base[0] = 0;
						}
						inning++;

					}

					

				}

				if (o == 3)
				{
					
					for (int j = 0; j < 4; j++)
					{
						base[j] = 0;
					}
					score += inning;
					break;
				}

			}
		}


		res = max(res, score);
	
	} while (next_permutation(&vc[1], &vc[9]));


	printf("%d", res);

	return 0;
}
