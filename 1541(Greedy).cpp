#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

char arr[51];
int aa[51];
vector<int> vc;

int greedy()
{
	int temp=0;
	int index = 0;
	int cnt = 0;
	int minus = 0;
	for(int i=0;i<strlen(arr);i++)
	{
		if (arr[i] == '-')
		{
			minus = 1;
			for (int j = 0; j <= index; j++)
			{
				cnt += aa[j];
			}
			memset(aa, 0, sizeof(aa) / sizeof(int));
			vc.push_back(cnt);
			index = 0;
			cnt = 0;
			
		}
		else if (arr[i] == '+')
		{
			index++;
		}
		else
		{
			aa[index] *= 10;
			aa[index] += arr[i]-'0';
		}
		
	}
	
	for (int j = 0; j <= index; j++)
	{
		cnt += aa[j];
	}
	vc.push_back(cnt);
	
	temp = vc[0];
	for (int i = 1; i < vc.size(); i++)
	{
		if (minus == 1)
		{
			temp -= vc[i];

		}
		else
		{
			temp += vc[i];
		}
	}

	return temp;

}

int main()
{
	
		scanf("%s", &arr);
	

		printf("%d", greedy());

		
	return 0;
}
