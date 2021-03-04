#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[101][10];
int N;
int main()
{
	scanf("%d", &N);
	int result = 0;

	for (int i = 1; i <= 9; i++)
		arr[1][i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
				arr[i][j] = arr[i-1][j + 1] % 1000000000;
			else if (j == 9)
				arr[i][j] = arr[i-1][j - 1] % 1000000000;
			else
				arr[i][j] = (arr[i-1][j - 1] + arr[i-1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++)
	{
		result += arr[N][i];
		result %= 1000000000;
	}

	printf("%d",result% 1000000000);
	return 0;
}