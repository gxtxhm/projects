#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int arr[10001] = { 0, };

int main() {
	
	int i, n,imsi;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &imsi);
		arr[imsi]++;
	}

	for (i = 1; i < 10001; i++)
	{
		while (arr[i] > 0)
		{
			printf("%d\n", i);
			arr[i]--;
		}
	}
	
	return 0;
}