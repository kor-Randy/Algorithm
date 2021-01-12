#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int N, S;
int arr[21];
int res, temp, cnt;
void com(int index)
{
	if (temp == S && index!=0)
	{
		res++;
	}
	//printf("index : %d , temp : %d\n", index, temp);
	for (int i = index; i < N; i++)
	{
		temp += arr[i];
		com(i + 1);
		temp -= arr[i];
	}

}

int main()
{
	scanf("%d %d", &N, &S);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	com(0);
		printf("%d", res);
	return 0;
}
