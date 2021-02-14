#include<stdio.h>


int sumOfdigit(int num)//각 자릿수의 합
{
	if (num < 10)return num;

	return num%10+sumOfdigit(num / 10);
}


int decomposition()
{
	int num,i;
	int decomposition = 0;
	scanf_s("%d", &num);

	for (i = 0; i < num; i++)
	{
		if (num == i + sumOfdigit(i))
		{
			decomposition = i;
			break;
		}
	}
	printf("%d", decomposition);
	return 0;
}