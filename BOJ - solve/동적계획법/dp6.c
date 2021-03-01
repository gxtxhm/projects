#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[501][501];
int N;

int dp[501][501];

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int findmax()
{
	int max = -1;
	for (int i = 0; i < N; i++)
	{
		if (dp[N - 1][i] > max)
			max = dp[N - 1][i];
	}
	return max;
}

int main()
{

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)//처음
			{
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			}
			else if (j == i)//마지막
			{
				dp[i][j] = dp[i - 1][j-1] + arr[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			}
		}

	}
	
	printf("%d",findmax());

	return 0;
}