#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[21][21];
vector<int> vc;
int N;
int temp, res,cnt;
int check[21];
int start, link;

void brute();

void com(int size, int index)
{

	if (size == N / 2)
	{
		//printf("size = %d\n", size);
		
		brute();
		check[index] = 0;
		return;

	}
	else
	{
	
		for (int i = index; i <= N; i++)
		{
			if (i + 1 > N)
				break;
			//printf("check[%d] = 1\n", i + 1);
			check[i + 1] = 1;
			//printf("com(%d,%d)", size+1,i + 1);
			com(size + 1, i + 1);
			check[i + 1] = 0;

		}
	}
}

void brute()
{
	

	
	for (int i = 1; i <= N; i++)
	{
		for (int j = i+1; j <= N; j++)
		{
			if (i == j)
				continue;
			else
			{
				if (check[i] == check[j] && check[i]==0)
				{
					start += (arr[i][j] + arr[j][i]);
				}
				else if (check[i] == check[j] && check[i] == 1)
				{
					link += (arr[i][j] + arr[j][i]);
				}
				
			}
		}
	}
	if ((start - link) < 0)
		vc.push_back(-(start - link));
	else
		vc.push_back((start - link));
	start = link = 0;

}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		check[i] = 1;
		com(1, i);
		check[i] = 0;
	}

	sort(vc.begin(), vc.end());

	printf("%d", vc[0]);


	return 0;
}
