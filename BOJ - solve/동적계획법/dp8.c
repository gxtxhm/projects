#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int N;

int dp[1000001];

int min(int a, int b)
{
	if (a >= b)
		return b;
	else
		return a;
}

int main()
{
	scanf("%d", &N);

	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;

	//-1,/2,/3 을 전부해보면서 1로만들었을 때 값이 가장 작은것을 dp[i]에 대입한다.
	//이 때, dp[i-1],dp[i/2],dp[i/3]은 이미 1로 만들때 몇번 연산하는지 구해놓았기 때문에
	// 가장 작은값에 +1만 하면 된다. Bottom - up방식
	for (int i = 4; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;  //-1을 하는 규칙을 적용한다. 
		if (i % 2 == 0)//만약 2로 나누어 떨어지면 -1을 적용하여 1로 만들때의 연산수와 
									//-1을 적용해 1로 만들때의 연산수를 비교하여 작은값을 대입한다. 
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0)//3으로도 나누어떨어진다면 위에서 구한 값과 /3을적용해 1로 만들었을때
										// 값을 비교하여 작은 값을 대입한다.
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	printf("%d", dp[N]);

	return 0;
}