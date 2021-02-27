#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


long long arr[101];

int main()
{
	int T,N;
	scanf("%d", &T);

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;

	for (int i = 6; i < 101; i++)
		arr[i] = arr[i - 1] + arr[i - 5];


	for(int i=0;i<T;i++)
	{
		scanf("%d", &N);
		printf("%lld\n", arr[N]);
	}
	return 0;
}