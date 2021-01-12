#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<unordered_set>
using namespace std;

vector<pair<int, int>> c;
unordered_set<string> visit;
pair<int, int> home;
string str;
pair<int, int> des;
int N, T;
string res;
bool compare(pair<int, int> a, pair<int, int> b)
{
	

	return abs(a.first) + abs(a.second) < abs(b.first) + abs(b.second);
}

void bfs()
{
	
	queue<pair<pair<int, int>,int>> q;
	q.push({ home ,20});

	while (1)
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int beer = q.front().second;
		//printf("x : %d , y : %d , beer : %d\n", x, y, beer);
		q.pop();

		if ((abs(des.first - x) + abs(des.second - y)) <= beer * 50)
		{
			printf("happy\n");
			res="happy";
			return;
		}

		for (int i = 0; i < c.size(); i++)
		{//모든 편의점 확인
			int nx = c[i].first;
			int ny = c[i].second;
			//printf("nx : %d , ny : %d \n", nx,ny);
			string name = to_string(nx) + to_string(ny);
			int d = abs(nx - x) + abs(ny - y);
			//printf("d : %d name : %s \n", d,name);

			if (d > (beer * 50))
				continue;
			else if (visit.find(name) != visit.end() && !visit.empty())
			{//이미 갔던 곳
				//printf("이미 갔던 편의점 %s\n", name);
				continue;
				
			}
			else
			{
				//printf("nx : %d , ny : %d삽입\n", nx, ny);
				visit.insert(name);
				q.push({ {nx,ny},20 });
			}
		}

		if (q.empty())
		{
			printf("sad\n");
			res = "sad";
			return;
		}


	
	}


}

int main()
{
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int a, b;
		scanf("%d", &N);
		scanf("%d %d", &a, &b);
		home = { a,b };
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d", &a, &b);
			c.push_back({ a,b });
		}
		scanf("%d %d", &a, &b);
		des = { a,b };

		bfs();

		//printf("%s\n", res);
		c.clear();
		visit.clear();

	}

	return 0;
}
