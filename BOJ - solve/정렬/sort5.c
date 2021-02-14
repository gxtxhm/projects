#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b)    // �������� �� �Լ� ����
{
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return 1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return -1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
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