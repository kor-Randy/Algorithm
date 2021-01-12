#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



int main()
{
	int answer=0;
	vector<int> vc = {1,2,3,4,5,6,7,8,9,10};
	int M = 56;


	int mi = 1;
	int ma = 100000;
	int md = 0;
	while (1)
	{
		if (mi + 1 == ma)
		{
			long long aa = 0, bb = 0;
			for (int i = 0; i<vc.size(); i++)
			{
				if (vc[i] <= mi)
					aa += vc[i];
				else
					aa += mi;

				if (vc[i] <= ma)
					bb += vc[i];
				else
					bb += ma;

				if (bb>M)
					answer = mi;
				else
					answer = ma;

			}
			break;
		}

		md = (mi + ma) / 2;
		printf("%d\n", md);
		long long temp = 0;
		for (int i = 0; i<vc.size(); i++)
		{
			if (vc[i] <= md)
				temp += vc[i];
			else
				temp += md;
		}
		if (temp<M)
		{
			mi = md;
		}
		else if (temp>M)
		{
			ma = md;
		}
		else
		{
			answer = md;
			break;
		}

	}

	printf("%d", answer);

	return 0;
}
