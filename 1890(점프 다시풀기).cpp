#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int N, M, K;
int res, temp;
int visit[151][151][151];
int xx[2] = { 0,1 };
int yy[2] = { 1,0 };
int dfs(int a, int b, int cnt, bool flag)
{
	if (cnt>N || a>M / 2 || b>M / 2)
		return 0;
	else if (a == M / 2 && b == M / 2 && cnt == N)
		return 1;
	else if (visit[a][b][cnt] != -1)
		return visit[a][b][cnt];
	else
	{
		visit[a][b][cnt] = 0;
		for (int i = 0; i<2; i++)
		{
			for (int j = 1; j <= K; j++)
			{
				int na = a + xx[i] * j;
				int nb = b + yy[i] * j;

				if (na>M / 2 || nb>M / 2)
					continue;
				else
				{
					visit[a][b][cnt] += dfs(na, nb, cnt + 1) % 1000000007;
					visit[a][b][cnt] %= 1000000007;
				}

			}
		}
		printf("%d , %d , %d , %d\n", a, b, cnt, visit[a][b][cnt]);
		return visit[a][b][cnt] % 1000000007;
	}

}

int main() {
	int answer = 0;
	N = 3;
	M = 8;
	K = 4;

	for (int i = 0; i <= M / 2; i++)
	{
		for (int j = 0; j <= M / 2; j++)
		{
			for (int k = 0; k <= N; k++)
			{
				visit[i][j][k] = -1;
			}
		}
	}

	if (N>M || N*K<M)
		return 0;

	answer = dfs(0, 0, 0);
	printf("%d", answer);



	return 0;
}