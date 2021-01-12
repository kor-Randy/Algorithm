#include<stdio.h>

int array[1001];

int main()
{
	int number,index , temp, min;

	scanf("%d", &number);

	for (int i = 0; i < number; i++)
	{
		scanf("%d", &array[i]);
	}

	for (int i = 0; i < number; i++)
	{
		min = array[i];
		index = i;
		
		for (int j = i+1; j < number; j++)
		{
			
			if (min > array[j])
			{
				min = array[j];
				index = j;

			}

		}

		temp = array[i];
		array[i] = min;
		array[index] = temp;


	}

	for (int i = 0;  i < number; i++)
	{
		printf("%d\n", array[i]);
	}

	return 0;
}