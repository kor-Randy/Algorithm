#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int arr[10];
int res, temp, cnt;
string str;
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	temp = a*b*c;
	str = to_string(temp);
	while (1)
	{
		int num = str[str.size() - 1] - '0';

		arr[num]++;
		str.pop_back();

		if (str.empty())
			break;

	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}


	return 0;
}
