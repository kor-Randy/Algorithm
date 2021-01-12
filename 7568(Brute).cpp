#include<stdio.h>
#include<algorithm>
#include<cstring>
using namespace std;

int N;
int kg[51], cm[51];
int arr[51];

void brute()
{

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (kg[i] < kg[j] && cm[i] < cm[j])
			{
				arr[i]++;
			}
			else if(kg[i] > kg[j] && cm[i] > cm[j])
			{
				arr[j]++;
			}
		}
	}

}

int main()
{



	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &kg[i], &cm[i]);
	}

	brute();

	for (int i = 0; i < N; i++)
	{
		printf("%d ",arr[i]+1);
		
	}
	return 0;
}