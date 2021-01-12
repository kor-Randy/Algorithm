#include<stdio.h>


using namespace std;

unsigned long long arr[91];

unsigned long long fibonacci(int n)
{
	
	if (n == 0)
	{
	
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else if (arr[n] != 0)
	{
		return arr[n];
	}
	else
	{
		return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}

}

int main()
{
	int N;
	scanf("%d", &N);

	printf("%llu", fibonacci(N));

	return 0;
}