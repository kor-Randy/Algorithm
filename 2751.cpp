#include<stdio.h>

int array[1000001];
int number;
int sort[1000001];

void merge(int data[], int m, int middle, int n)
{

	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle&&j <= n)
	{
		
		if (data[i] <= data[j])
		{
			sort[k] = data[i];
			i++;
		}
		else
		{
			sort[k] = data[j];
			j++;
		}

		k++;

	}

	if (i > middle)
	{
		for (int t = j; t <= n; t++)
		{
			sort[k] = data[t];
			k++;
		}
	}
	if (j > n)
	{
		for (int t = i; t <= middle; t++)
		{
			sort[k] = data[t];
			k++;
		}
	}

	for (int t = m; t <= n; t++)
	{
		data[t] = sort[t];
	}



}

void mergeSort(int data[], int m, int n)
{
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergeSort(data, m, middle);
		mergeSort(data, middle + 1, n);
		merge(data, m, middle, n);
	}
}


int main()
{


	scanf("%d", &number);

	for (int i = 0; i < number; i++)
	{
		scanf("%d", &array[i]);
	}

	mergeSort(array, 0, number - 1);

	for (int i = 0; i < number; i++)
	{
		printf("%d", array[i]);
	}



	
	return 0;
}