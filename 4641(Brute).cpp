#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

int arr[16];
int res;
int index;
void brute()
{
	sort(&arr[0], &arr[index]);

	for (int i = 0; i < index; i++)
	{
		if (i == index)
			break;

		for (int j = i + 1; j < index; j++)
		{
			if (arr[j] == arr[i] * 2)
			{
				res++;
				break;
			}
			else if (arr[j] > arr[i] * 2)
				break;
			
		}
	}

}

int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a = 100;
	while (a != -1)
	{
		
		cin >> a;
		if (a == 0)
		{
			brute();
			printf("%d\n", res);
			index = 0;
			res = 0;
		}
		else
			arr[index++] = a;

		

	}


	return 0;
}
