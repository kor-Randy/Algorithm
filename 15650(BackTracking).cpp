#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int N, M;
int arr[9];
int visit[9];
int temp, res, cnt;
vector<int> vc;

void func(int index)
{

	if (cnt == M)
	{
		for (int i = 0; i < vc.size(); i++)
		{
			printf("%d ", vc[i]);
			
		}
		printf("\n");
		return;
	}
	else
	{
		for (int i = index+1; i <= N; i++)
		{
		
			vc.push_back(i);
				cnt++;
				func(i);
				vc.pop_back();
				cnt--;
			

		}
	}

}

int main()
{
	scanf("%d %d", &N, &M);


	func(0);


	return 0;
}
