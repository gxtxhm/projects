#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[50][50][50];

int w(int a, int b, int c)
{
	int w1 = 0, w2 = 0, w3 = 0, w4 = 0;
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	if (a > 20 || b > 20 || c > 20)
	{
		int w1 = 0;
		if (arr[20][20][20] != 0)
			w1 = arr[20][20][20];
		else
		{
			w1 = w(20, 20, 20);
			arr[20][20][20] = w1;
		}
		return w1;
	}

	if (a < b && b < c)
	{
		int w1 = 0, w2 = 0, w3 = 0;


		if (arr[a][b][c - 1] != 0)//계산한 값이 있다면
			w1 = arr[a][b][c - 1];
		else
		{
			w1 = w(a, b, c - 1);
			arr[a][b][c - 1] = w1;
		}

		if (arr[a][b - 1][c - 1] != 0)//계산한 값이 있다면
			w2 = arr[a][b - 1][c - 1];
		else
		{
			w2 = w(a, b - 1, c - 1);
			arr[a][b - 1][c - 1] = w2;
		}

		if (arr[a][b - 1][c] != 0)//계산한 값이 있다면
			w3 = arr[a][b - 1][c];
		else
		{
			w3 = w(a, b - 1, c);
			arr[a][b - 1][c] = w3;
		}
		return w1 + w2 - w3;
	}

	if (arr[a - 1][b][c] != 0)//계산한 값이 있다면
		w1 = arr[a - 1][b][c];
	else
	{
		w1 = w(a - 1, b, c);
		arr[a - 1][b][c] = w1;
	}

	if (arr[a - 1][b - 1][c] != 0)//계산한 값이 있다면
		w2 = arr[a - 1][b - 1][c];
	else
	{
		w2 = w(a - 1, b - 1, c);
		arr[a - 1][b - 1][c] = w2;
	}

	if (arr[a - 1][b][c - 1] != 0)//계산한 값이 있다면
		w3 = arr[a - 1][b][c - 1];
	else
	{
		w3 = w(a - 1, b, c - 1);
		arr[a - 1][b][c - 1] = w3;
	}

	if (arr[a - 1][b - 1][c - 1] != 0)//계산한 값이 있다면
		w4 = arr[a - 1][b - 1][c - 1];
	else
	{
		w4 = w(a - 1, b - 1, c - 1);
		arr[a - 1][b - 1][c - 1] = w4;
	}

	return w1 + w2 + w3 - w4;
}


int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	while (!(a == -1 && b == -1 && c == -1))
	{
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
		scanf("%d %d %d", &a, &b, &c);
	}

	return 0;
}