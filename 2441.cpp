#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main()
{

	int x,y;
	scanf("%d %d", &x,&y);

	for (int i = 1; i < x; i++)
	{
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			y += 31;
		}
		else if (i == 4 || i == 6 || i == 9 || i == 11)
		{
			y += 30;
		}
		else
		{
			y += 28;
		}
	}
	switch (y % 7)
	{
		case 0:
			printf("MON");
			break;
		case 1:
			printf("TUE");
			break;
		case 2:
			printf("WED");
			break;
		case 3:
			printf("THU");
			break;
		case 4:
			printf("FRI");
			break;
		case 5:
			printf("SAT");
			break;
		case 6:
			printf("SUN");
			break;

			
	}


	return 0;
}