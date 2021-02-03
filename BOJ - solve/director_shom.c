#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>


char a[100] = {0,};
int IsDevilNumber(int num)
{

	char* ptr = NULL;
	sprintf(a, "%d", num);
	ptr=strstr(a, "666");
	
	if (ptr != NULL)
		return 1;
	else
		return 0;
}



int main()
{
	int i=666,N,cnt=0;
	scanf("%d", &N);

	while (N != cnt)
	{
		if (IsDevilNumber(i) == 1)
		{
			cnt++;
		}
		i++;
	}

	printf("%d", i - 1);
	return 0;
}