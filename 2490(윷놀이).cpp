#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[4];

int main()
{
	for (int i = 0; i < 3; i++)
	{
		
			scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
		

		int a = arr[0] + arr[1] + arr[2] + arr[3];

		if (a == 0)
			printf("D\n");
		else if (a == 1)
			printf("C\n");
		else if (a == 2)
			printf("B\n");
		else if (a == 3)
			printf("A\n");
		else
			printf("E\n");

	}

	return 0;
}
