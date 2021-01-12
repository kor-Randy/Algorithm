#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int K;

char arr[11];
int temp[11];
int check[11];
string str;
string ma, mi;

int main()
{
	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		cin >> arr[i];
	}
	

	for (int i = 0; i < K; i++)
	{
		for (int j = i; j < K; j++)
		{
			if (arr[j] == '<')
				temp[i]++;
			else
				break;
		}
	}
	


	for (int i = 0; i < K + 1; i++)
	{
		int a = 0;
		for (int j = 9; j >= 0; j--)
		{
			if (check[j] == 0)
			{
				a++;
			}
			if (a == temp[i] + 1)
			{
				ma += (char)(j+'0');
				check[j] = 1;
				break;
			}
		}
		

	}


	for (int i = 0; i < K+1; i++) {
		temp[i] = 0;
	}

	for (int i = 0; i <= 9; i++)
		check[i] = 0;


	for (int i = 0; i < K; i++)
	{
		for (int j = i; j < K; j++)
		{
			if (arr[j] == '>')
				temp[i]++;
			else
				break;
		}
	}

	for (int i = 0; i < K+1; i++)
	{
		int a = 0;
		for (int j = 0; j <= 9; j++)
		{
			if (check[j] == 0)
			{
				a++;
			}
			if (a == temp[i] + 1)
			{
				mi += (char)(j + '0');
				check[j] = 1;
				break;
			}
		}

	}

	cout << ma << "\n" << mi ;


	return 0;
}
