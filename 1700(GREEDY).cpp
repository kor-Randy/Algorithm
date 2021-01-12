#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, K;
queue<int> q[101];
int cnt, res, temp;
int arr[101];
vector<int> vc;
int temp1;
void greedy()
{
	
	vc.push_back(arr[0]);
	q[arr[0]].pop();
	for (int i = 1; i < K; i++)
	{
		temp = 0;
		/*for (int j = 0; j < vc.size(); j++)
			printf("%d ", vc[j]);
		printf("\n");

		*/


		temp1 = 0;
		if (vc.size() < N)
		{
			for (int j = 0; j < vc.size(); j++)
			{
				if (arr[i] == vc[j])
				{
					temp1 = 1;
					q[arr[i]].pop();
					break;
				}
			}
			if (temp1 == 1)
				continue;
			
				vc.push_back(arr[i]);
				q[arr[i]].pop();
			
		}
		else
		{
			for (int j = 0; j < vc.size(); j++)
			{
				if (arr[i] == vc[j])
				{
					temp1 = 1;
					q[arr[i]].pop();
					break;
				}
			}
			if (temp1 == 1)
				continue;
			for (int j = 0; j < vc.size(); j++)
			{
				if (q[vc[j]].empty())
				{
					vc.erase(vc.begin() + j);
					cnt++;
					vc.push_back(arr[i]);
					q[arr[i]].pop();
					temp1 = 1;
					break;
				}
			}
				
				
			
			if (temp1 == 1)
				continue;
			if (vc.size() >= N)
			{
				int change = 0;
				for (int j = 0; j < vc.size(); j++)
				{
					if (q[vc[j]].empty())
					{
						change = j;
						break;
					}
					else if (temp < q[vc[j]].front())
					{
						temp = q[vc[j]].front();
						change = j;
					}

				}
				
					vc.erase(vc.begin() + change);
					cnt++;
					vc.push_back(arr[i]);
					q[arr[i]].pop();
				
			}
		}

	}

}

int main()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < K; i++)
	{
		int temp;
		scanf("%d", &temp);
		arr[i] = temp;
		q[temp].push(i);
	}

	greedy();

	printf("%d", cnt);

	return 0;
}
