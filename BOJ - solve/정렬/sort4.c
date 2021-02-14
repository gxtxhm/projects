#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
{
	int num1 = *(int*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
	int num2 = *(int*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

	if (num1 < num2)    // a가 b보다 작을 때는
		return -1;      // -1 반환

	if (num1 > num2)    // a가 b보다 클 때는
		return 1;       // 1 반환

	return 0;    // a와 b가 같을 때는 0 반환
}

int arr[500000] = { 0, };

int main()
{
	int n,i,modeCnt=0;//modeCnt==최빈값몇번째인지
	double cnt = 0;//총합
	int average = 0;//평균
	int arr2[8003] = { 0, };//-4001~4001까지수의 빈도수를 담는다. 음수는 4002~8002로대체한다.
	int mode1=0, mode2=0;//mode1 == 최빈값의 빈도수, mode2는 최빈값

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		//음수 증가
		//총합계산 및 빈도수 증가시키기
		if (arr[i] < 0)
			arr2[arr[i]*-1 + 4001]++;
		else
			arr2[arr[i]]++;
		cnt += arr[i];
	}
	//퀵정렬
	qsort(arr, n, sizeof(int), compare);

	//음수,양수 반올림 처리
	if (cnt < 0)
	{
		average = (int)(cnt / n - 0.5);
	}
	else
	{
		average = (int)(cnt / n + 0.5);
	}
	
	//산술평균
	printf("%d\n", average);
	//중간값
	printf("%d\n", arr[n / 2]);
	//최빈값
	//음수구간부터 양수구간으로 순서대로 확인한다.
	//음수구간
	for (i = 8002; i >= 4002; i--)
	{
		//기존 가장높은 빈도수보다 높은 빈도수가 나오면
		if (mode1 < arr2[i])
		{
			modeCnt = 1;//가장 작은 최빈값
			mode2 = (i - 4001) * -1;
			if (modeCnt != 2)//두번째 최빈값을 유지하기 위함이다.
			{
				mode1 = arr2[i];
			}
		}
		//동일한 빈도수이면서 두번째로 작은 최빈값이라면
		else if (mode1 == arr2[i] && modeCnt < 2)
		{
			modeCnt++;

			mode2 = (i - 4001) * -1;
		}
	}
	//양수구간
	for (i = 0; i < 4002; i++)
	{
		
			if (mode1 < arr2[i])
			{
				modeCnt = 1;
				mode2 = i;
				if (modeCnt != 2)
				{
					mode1 = arr2[i];
				}
			}
			else if (mode1 == arr2[i] && modeCnt < 2)
			{
				modeCnt++;
				mode2 = i;
			}
	}
	printf("%d\n", mode2);
	//범위
	printf("%d\n", arr[n - 1] - arr[0]);
	return 0;
}