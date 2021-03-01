//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int arr[1001][3];//최대 천개의 집에 칠한 색
//int N;
//
//int dp[1001][3];
//
//int min(int a, int b)
//{
//	if (a <= b)
//		return a;
//	else
//		return b;
//}
//
//int main()
//{
//	
//	scanf("%d", &N);
//	for (int i = 1; i <= N; i++)
//	{
//		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
//	}
//	
//	dp[1][0] = arr[1][0];
//	dp[1][1] = arr[1][1];
//	dp[1][2] = arr[1][2];
//
//	for (int i = 2; i <= N; i++)
//	{
//		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
//		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
//		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + arr[i][2];
//	}
//	printf("%d", min(min(dp[N][0], dp[N][1]), dp[N][2]));
//	
//	return 0;
//}