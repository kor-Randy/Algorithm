#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>


using namespace std;


int arr[301][3];

int dp(int value[], int x,int last)
{
	
	
	if (x == 1)
	{
		arr[1][1] = value[1];
		arr[1][2] = 0;
		arr[1][0] = max(arr[1][1],arr[1][2]);
		
	}
	if (x == 2)
	{
		arr[2][1] = arr[1][0]+value[2];
		arr[2][2] = value[2];
		arr[2][0] = max(arr[2][1], arr[2][2]);
		
	}
	if (arr[x][last] != 0) return arr[x][last];

	
	arr[x][1] = (dp(value, x - 1, 2) + value[x]);
	arr[x][2] = (dp(value, x - 2, 0) + value[x]);
	arr[x][0] = max(arr[x][1], arr[x][2]);

	return arr[x][last];
	
}


int main()
{
	int number;
	scanf("%d", &number);
	int *value = new int[number+1];

	for (int i = 1; i < number + 1; i++)
	{
		scanf("%d", &value[i]);
	}

	dp(value, number,0);

	


	

	printf("%d", arr[number][0]);

	





	return 0;
}
