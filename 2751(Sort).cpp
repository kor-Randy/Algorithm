#include<stdio.h>

#include<algorithm>
using namespace std;

int arr[1000001];
int N;
void quick(int start, int end)
{
	int left = start;
	int right = end;
	int pivot = start + 1;

	if (start>=end)
	{
		return;
	}

	while (left<right)
	{
		
		while (arr[left] < arr[pivot] && left <end)
		{
			left++;
		}
		while (arr[right] >= arr[pivot] && right>pivot)
		{
			
			right--;
			
		}
		if(left>=right)
		{
			//start와 end가 pivot에 도착하면 start ~ pivot-1 / pivot+1 ~ end 를 재귀 수행
			int temp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = temp;
			
		}
		else
		{
			int temp = arr[right];
			arr[right] = arr[left];
			arr[left] = temp;
		}

	}

	quick(start, right - 1);

	quick(right+1, end);

}


int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	sort(&arr[0], &arr[N]);

	for (int i = 0; i < N; i++)
	{
		printf("%d\n", arr[i]);
	}

	
	return 0;
}