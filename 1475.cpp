#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int arr[10];
int N;
string str;
int main()
{
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		int num = str[i] - '0';

		if (num == 9)
			arr[6]++;
		else
			arr[num]++;

	}

	if ((double)arr[6] / 2 == arr[6] / 2)
		arr[6] /= 2;
	else
		arr[6] = (arr[6] / 2) + 1;

	sort(&arr[0], &arr[9]);

	printf("%d", arr[8]);



	return 0;
}
