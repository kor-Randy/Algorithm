#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;

int N;
int arr[500001];
vector<int> vc;
stack<pair<int, int>> st;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);


	for (int i = 0; i < N; i++)
	{
	
		while (1)
		{
			if (st.empty())
			{
				vc.push_back(0);
				st.push({ i + 1,arr[i] });
				break;
			}

			if (arr[i] > st.top().second)
			{
				st.pop();
				
			}
			else
			{
				vc.push_back(st.top().first);
				st.push({ i + 1,arr[i] });
				break;
			}
			
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d ", vc[i]);

	return 0;
}
