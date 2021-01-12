#include<stdio.h>
#include<iostream>
using namespace std;

int N;

unsigned long long arr[9] = { 9,90,900,9000,90000,900000,9000000,90000000 };

unsigned long long brute()
{
	if (N < 10)
	{
		return N;
	}
	else if (N < 100)
	{
		return arr[0] + (N - 9) * 2;
	}
	else if (N < 1000)
	{
		return arr[0] + arr[1] * 2 + (N - 99) * 3;
	}
	else if (N < 10000)
	{
		return arr[0] + arr[1] * 2 + arr[2] * 3 + (N - 999) * 4;
	}
	else if (N < 100000)
	{
		return arr[0] + arr[1] * 2 + arr[2] * 3 + arr[3] * 4 + (N - 9999) * 5;
	}
	else if (N < 1000000)
	{
		return arr[0] + arr[1] * 2 + arr[2] * 3 + arr[3] * 4 + arr[4] * 5 + (N - 99999) * 6;
	}
	else if (N < 10000000)
	{
		return arr[0] + arr[1] * 2 + arr[2] * 3 + arr[3] * 4 + arr[4] * 5 + arr[5] * 6 + (N - 999999) * 7;
	}
	else if (N < 100000000)
	{
		return arr[0] + arr[1] * 2 + arr[2] * 3 + arr[3] * 4 + arr[4] * 5 + arr[5] * 6 + arr[6] * 7 + (N-9999999)*8;
	}
	else if (N == 100000000)
	{
		return arr[0] + arr[1] * 2 + arr[2] * 3 + arr[3] * 4 + arr[4] * 5 + arr[5] * 6 + arr[6] * 7 +arr[7]*8+ 9;
	}


}

int main()
{
	scanf("%d",&N);

	printf("%llu", brute());
	

	return 0;
}
