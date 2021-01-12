#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int arr[1001][3];
int red[1001];
int blue[1001];
int green[1001];
vector<int> vc;


void dp(int n)
{
	arr[0][0] = red[0];
	arr[0][1] = green[0];
	arr[0][2] = blue[0];

	


	for (int i = 1; i < n; i++)
	{
		arr[i][0] = min(arr[i - 1][1] + red[i], arr[i - 1][2] + red[i]);
		arr[i][1] = min(arr[i - 1][0] + green[i], arr[i - 1][2] + green[i]);
		arr[i][2] = min(arr[i - 1][0] + blue[i], arr[i - 1][1] + blue[i]);
	}

}

int main()
{
	
	

	
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d %d %d", &red[i],&green[i],&blue[i]);

			
			
		}

		dp(N);

		printf("%d", min(min(arr[N - 1][0], arr[N - 1][1]), arr[N - 1][2]));
	
	

	return 0;
}