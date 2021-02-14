#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct memberInfo {
	char name[101];//널값 들어가야 해서 1 추가
	int age;
	int orderOfmember;
}Member;

Member member[100000];

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	Member num1 = *(Member*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	Member num2 = *(Member*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1.age < num2.age)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1.age > num2.age)    // a가 b보다 클 때는
		return 1;       // 1 반환

	if (num1.age == num2.age)
	{
		if (num1.orderOfmember < num2.orderOfmember)
			return -1;
		if (num1.orderOfmember > num2.orderOfmember)
			return 1;
		return 0;
	}

	return 0;    // a와 b가 같을 때는 0 반환
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