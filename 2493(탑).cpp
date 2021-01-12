#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int N;
int d[500001];
stack<pair<int,int>> st;



int main()
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		int a;
		cin >> a;

		while (1) {
			if (st.empty()) {
				st.push({ i,a });
				d[i] = 0;
				break;
			}
			else {
				//������ ������� ������
				if (a >= st.top().second) {
					//���� ���̰� ������ Top�� ���̺��� Ŭ ��
					st.pop();
				}
				else {
					d[i] = st.top().first;
					st.push({ i,a });
					break;
				}
			}
		}
		
	}
		
	for (int i = 1; i <= N; i++) {
		printf("%d ", d[i]);
	}


	return 0;
}
