#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct memberInfo {
	char name[101];//�ΰ� ���� �ؼ� 1 �߰�
	int age;
	int orderOfmember;
}Member;

Member member[100000];

int compare(const void* a, const void* b)    // �������� �� �Լ� ����
{
	Member num1 = *(Member*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	Member num2 = *(Member*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1.age < num2.age)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1.age > num2.age)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	if (num1.age == num2.age)
	{
		if (num1.orderOfmember < num2.orderOfmember)
			return -1;
		if (num1.orderOfmember > num2.orderOfmember)
			return 1;
		return 0;
	}

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}



int main()
{
	int N, i;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d %s", &member[i].age, member[i].name);
		member[i].orderOfmember = i+1;
	}
	
	qsort(member, N, sizeof(Member), compare);

	for (i = 0; i < N; i++)
	{
		printf("%d %s\n", member[i].age, member[i].name);
	}
	return 0;
}