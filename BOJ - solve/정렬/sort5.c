#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return 1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return -1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

int main()
{
	int n;
	int cnt = 0;
	int arr[10] = { 0, };
	scanf("%d", &n);

	while (n > 0)
	{
		arr[cnt] = n % 10;
		n = n / 10;
		cnt++;
	}
	qsort(arr, cnt, sizeof(int), compare);

	for (int i = 0; i < cnt; i++)
	{
		printf("%d", arr[i]);
	}
	return 0;
}