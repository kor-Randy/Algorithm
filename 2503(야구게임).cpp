#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;



int N;
string str, temp;
int a, b, c;
int arr[1000];
int st, ba;
int res;
void find()
{
	
	for (int i = 123; i <1000; i++)
	{
		ba = st = 0;
		temp = to_string(i);
		if (arr[i]==0)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (str[j] == temp[k] && j == k)
						st++;
					else if(str[j] == temp[k])
						ba++;
				}
			}

			if (st == b&&ba == c)
			{

			}
			else
				arr[i] = 1;

		}
	}

}

int main()
{
	scanf("%d", &N);

	for (int i = 123; i < 1000; i++)
	{
		int temp = i;
		int t1, t2, t3;
		t1 = temp % 10;
		temp = temp / 10;
		t2 = temp % 10;
		temp = temp / 10;
		t3 = temp % 10;

		if (t1 == t2 || t1 == t3 || t2 == t3 || t1==0 || t2==0 || t3==0 )
		{
			arr[i] = 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		str = to_string(a);

		find();
	}

	for (int i = 123; i <1000; i++)
	{
		if (arr[i] == 0)
			res++;
	}
	printf("%d", res);

	return 0;
}
