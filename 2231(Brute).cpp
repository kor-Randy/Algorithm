#include<stdio.h>
#include<algorithm>
#include <string.h>
#include<cmath>

using namespace std;

int N;
int res,temp,temp1;
int arr[6];
int brute()
{
	res = 1000001;
	for (int i = N - 54; i <= N - 6; i++)
	{
		memset(arr, 0, sizeof(arr));
		int a=i;
		for(int j=0;j<6;j++)
		{
			if (a == 0)
				break;
			arr[j] = a % 10;
			temp += arr[j];
			a = a / 10;
		}
		for (int j = 0; j < 6; j++)
		{
			temp1 += (arr[j] * pow(10, j));
		}
		if (temp1 + temp == N)
		{
			res = min(res, temp1);
		}

		temp1 =temp= 0;
	}
	if (res < 1000000)
		return res;
	else
		return 0;
}

int main()
{
	scanf("%d", &N);

	printf("%d", brute());

	return 0;
}