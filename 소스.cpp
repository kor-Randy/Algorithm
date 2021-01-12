#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;



const int MAX = 40000;



int N;

int connect[MAX + 1];

int cache[MAX + 1];



//O(n^2)는 시간초과

/*

int portLIS(int leftPort)

{

int &result = cache[leftPort + 1];

if (result != -1)

return result;



result = 0;

for (int next = leftPort + 1; next < N; next++)

//왼쪽 포트번호가 1이거나 다음 연결할 포트번호가 더 커 꼬이지 않을 경우

if (leftPort == -1 || connect[leftPort] < connect[next])

{

int candidate = 1 + portLIS(next);

result = max(result, candidate);

}

return result;

}



int main(void)

{

cin >> N;



for (int i = 0; i < N; i++)

cin >> connect[i];



memset(cache, -1, sizeof(cache));

//원래대로라면 idx=1부터 입력받으므로 0부터 시작해야하지만

//connect 배열을 idx=0부터 입력받았으므로 -1에서 시작

cout << portLIS(-1) << endl;

return 0;

}

*/



//O(nlogn) 안에 실행되어야함

int portLIS(void)

{

	//초기 값

	cache[1] = connect[1];

	int length = 1;

	for (int i = 2; i <= N; i++)

	{

		if (cache[length] < connect[i]) //선이 안 꼬일 경우 추가하고 continue

		{

			cache[++length] = connect[i];

			continue;

		}

		//i번째 왼쪽 포트에 연결되어있는 오른쪽 포트의 번호보다 작지 않은 최초의 위치 탐지

		int idx = lower_bound(cache + 1, cache + length + 1, connect[i]) - cache;

		cache[idx] = connect[i];

		for (int j = 1; j <= length; j++)
		{
			printf("%d ", cache[j]);
		}
		printf("\n");

	}

	return length;

}



int main(void)

{

	cin >> N;



	for (int i = 1; i <= N; i++)

		cin >> connect[i];



	cout << portLIS() << endl;

	return 0;

}