#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int N;
int sum,cnt;
int go()
{
	int temp = N;

	while (1)
	{
		if (temp == N && cnt!=0)
			break;

		sum = (temp % 10) + (temp / 10) % 10;
		temp = (temp % 10) * 10 + (sum % 10);
		cnt++;




	}
	return cnt;


}

int main()
{
	scanf("%d", &N);

	printf("%d", go());

	return 0;
}