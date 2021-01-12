#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;



const int MAX = 40000;



int N;

int connect[MAX + 1];

int cache[MAX + 1];



//O(n^2)�� �ð��ʰ�

/*

int portLIS(int leftPort)

{

int &result = cache[leftPort + 1];

if (result != -1)

return result;



result = 0;

for (int next = leftPort + 1; next < N; next++)

//���� ��Ʈ��ȣ�� 1�̰ų� ���� ������ ��Ʈ��ȣ�� �� Ŀ ������ ���� ���

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

//������ζ�� idx=1���� �Է¹����Ƿ� 0���� �����ؾ�������

//connect �迭�� idx=0���� �Է¹޾����Ƿ� -1���� ����

cout << portLIS(-1) << endl;

return 0;

}

*/



//O(nlogn) �ȿ� ����Ǿ����

int portLIS(void)

{

	//�ʱ� ��

	cache[1] = connect[1];

	int length = 1;

	for (int i = 2; i <= N; i++)

	{

		if (cache[length] < connect[i]) //���� �� ���� ��� �߰��ϰ� continue

		{

			cache[++length] = connect[i];

			continue;

		}

		//i��° ���� ��Ʈ�� ����Ǿ��ִ� ������ ��Ʈ�� ��ȣ���� ���� ���� ������ ��ġ Ž��

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