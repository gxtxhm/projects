#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int N;
int arr[301];

int dp[301];


int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}


int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	dp[0] = arr[0];
	dp[1] = max(arr[1], arr[0] + arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < N; i++)
	{

		dp[i] = max(dp[i - 3] + arr[i - 1], dp[i - 2]) + arr[i];
		
	}
	printf("%d", dp[N - 1]);
	return 0;
}