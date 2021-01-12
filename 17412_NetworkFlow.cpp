#include<stdio.h>
#include<iostream>

#define one 1000;
#define two 5000;
#define three 10000;
#define four 50000;

using namespace std;


int weather[10], bitCoin[10], feeling[10], figthDateWithFather[10];
float myGrade[10];
// weather : 1->비옴 2-> 눈옴 3-> 흐림 4->맑음
//feeling : 1->매우안좋음 2-> 약간안좋음 3-> 보통 4-> 좋음 5-> 매우 좋음
//bitCoin : n 만원
//fightDateWithFather : 아빠와 싸운지 n 일
//myGrade : 나의 학점

// 1 1400 1 100 4.5 -> 10000

int calcul(int weather, int feeling, int bitcoin ,float mygrade,int fightdate )
{

	
	if (bitcoin >= 2000)
	{
		return 50000;
	}
	else if (bitcoin < 1000)
	{
		return 1000;
	}
	else
	{
		
		int grade;

		grade = feeling * 10 + weather * 5 + mygrade * 3;

		if (grade >= 60)
		{
			return 50000;
		}
		else if (grade >= 40 && grade < 60)
		{
			return 10000;
		}
		else if (grade >= 30 && grade < 40)
		{
			return 5000;
		}
		else
		{
			return 1000;
		}

		
	}
	

}




int main()
{
	int temp=0;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d %d %d %d %f", &weather[i], &bitCoin[i], &feeling[i], &figthDateWithFather[i], &myGrade[i]);

		
	
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d %d %d %d %.1f", weather[i], bitCoin[i], feeling[i], figthDateWithFather[i], myGrade[i]);

		printf(" %d\n", calcul(weather[i], feeling[i], bitCoin[i], myGrade[i], temp));

	}
	

	return 0;
}