#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int L, C;
int res, temp, cnt;
char arr[16];
string str;
vector<string> vc;
int visit[16];
int j, m;

void dfs(int index, int c)
{
	//printf("index  : %d, c : %d \n", index,c);
	if (c == C)
	{
		//printf("출력");
		if (j >= 2 && m >= 1)
			vc.push_back(str);
		return;
	}
	else
	{
		
		for (int i = 0; i < L; i++)
		{
			if (str[str.size() - 1] > arr[i] || visit[i]==1)
				continue;
			//printf("%c 추가\n", arr[i]);
			str += arr[i];
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i'||arr[i] == 'o' || arr[i] == 'u')
				m++;
			else
				j++;
			visit[i] = 1;
			dfs(i, c + 1);
			if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i'||arr[i] == 'o' || arr[i] == 'u')
				m--;
			else
				j--;
			visit[i] = 0;
			str.pop_back();
		}

	}

}

int main()
{
	scanf("%d %d", &C, &L);

	for (int i = 0; i < L; i++)
	{
		scanf(" %c", &arr[i]);
	}

	for (int i = 0; i < L; i++)
	{
		str += arr[i];
		visit[i] = 1;
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			m++;
		else
			j++;
			
		dfs(i, 1);
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			m--;
		else
			j--;
		visit[i] = 0;
		str.pop_back();
	}

	sort(vc.begin(), vc.end());

	for (int i = 0; i < vc.size(); i++)
		cout << vc[i] << "\n";

	return 0;
}
