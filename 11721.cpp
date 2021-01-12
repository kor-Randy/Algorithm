#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

int main()
{

	
	char a[101];
	
	
	scanf("%s", &a);

	int num = strlen(a);
	int start = 0;

	while (num>0)
	{
		if (num > 9)
		{
			for (int i = start; i < start+10; i++)
			{


				printf("%c", a[i]);

				
			}
			num -= 10;
			start += 10;
		}
		else
		{	
		
			for (int i = start; i < start+num; i++)
			{
				printf("%c", a[i]);

				
			}
			num = 0;

		}
		printf("\n");
	}
	



	return 0;
}