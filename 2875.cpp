#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int N, M,K;
int main()
{
	scanf("%d %d %d", &N, &M, &K);

	int a, b, c;
	int team = 0;
	a = N / 2;//여자/2
	
	b = M;//남자
	c = N + M; // 총학생
	team = min(a, b);//나올 수 있는 대회 팀 수
	int temp = c - team * 3;//남는 사람 수
	if(K<=temp)
	{
		printf("%d", team);
	}
	else
	{
		K -= temp;
		if ((double)K / 3 == K / 3)
		{
			//나누어 떨어짐
			team -= K / 3;
		}
		else
		{
			team -= (K / 3) + 1;
		}
		printf("%d", team);
	}


	return 0;
}
