#include<stdio.h>
#include<iostream>
using namespace std;

int N, M;
int arr[301][301];
int res;


int main()
{
	scanf("%d %d", &N, &M);

	printf("%d", (N-1)+(M-1)*N);

	return 0;
}
