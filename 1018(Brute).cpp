#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;

int N, M;
char arr[51][51];
int res,temp,temp1;
char one,two;
char buf;

void brute()
{

	res = 5000;
	
	for (int i = 0; i < N - 7; i++)
	{
		for (int j = 0; j < M - 7; j++)
		{
			one = arr[i][j];
			if (one == 'B')
				two = 'W';
			else
				two = 'B';

			for (int k = 0; k < 8; k++)
			{
				for (int l = 0; l < 8; l++)
				{
					if (k % 2 == 0)
					{
						if (l % 2 == 0)
						{
							if (arr[i + k][j + l] != one)
								temp++;
							else if (arr[i + k][j + l] != two)
								temp1++;

							
						}
						else
						{
							if (arr[i + k][j + l] != two)
								temp++;
							else
								temp1++;
						}
					}
					else
					{
						if (l % 2 == 0)
						{
							if (arr[i + k][j + l] != two)
								temp++;
							else
								temp1++;

						}
						else
						{
							if (arr[i + k][j + l] != one)
								temp++;
							else
								temp1++;
						}
					}
				}
			}
			temp = min(temp, temp1);
			res = min(res, temp);
			temp = 0;
			temp1 = 0;

		}
	}

}


int main()
{
	scanf("%d %d", &N, &M);

	scanf("%c", &buf);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%c", &arr[i][j]);
		}
		scanf("%c", &buf);
	}

	brute();

	printf("%d", res);


	return 0;
}