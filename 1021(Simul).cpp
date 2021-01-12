#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;

int N, M;

deque<int> dq;
int arr[51];
int res, temp, cnt;
vector<int> vc;

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}
	for (int i = 0; i < M; i++)
		scanf("%d", &arr[i]);

	int index = 0;
	int m = 0;
	while (1)
	{
		if (dq.front() == arr[index])
		{
			index++;
			m++;
			dq.pop_front();
			if (m == M)
				break;
		}
		else
		{

			int left = 0;
			for (auto i = dq.begin(); i != dq.end(); i++)
			{
				if (*i == arr[index])
				{
					break;
				}
				else
				{
					left++;
				}
			}
			int right = dq.size() - left;

			if (left <= right)
			{
				while (1)
				{
					dq.push_back(dq.front());
					dq.pop_front();
					left--;
					res++;

					if (left == 0)
						break;
				}
			}
			else
			{
				while (1)
				{
					dq.push_front(dq.back());
					dq.pop_back();
					right--;
					res++;

					if (right == 0)
						break;
				}
			}


		}
		
	
	}

	printf("%d", res);



	return 0;
}
