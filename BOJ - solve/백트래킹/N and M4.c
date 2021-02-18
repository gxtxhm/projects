#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int isUsedNumArr[9] = { 0, };//사용한 숫자는 1, 미사용한 숫자는 0
int sequence[9] = { 0, };//수열의 경우의 수 중에서 1개가 저장된다.
int N;//사용할 자연수의 개수 1부터 시작
int M;//N개의 자연수 중에서 M개를 골라서 수열을 만든다.

int IsAscending()//오름차순인가 체크해주는 함수
{
	int i;
	for (i = 1; i < M; i++)
	{
		if (sequence[i] > sequence[i + 1])
			return 0;
	}
	return 1;
}
void PrintSequenceAll(int cnt)//모든 경우의 순열을 출력
{
	int i;
	//cnt번째 자리에 들어갈 수 찾기
	for (i = 1; i <= N; i++)
	{


		sequence[cnt] = i;//수열의 cnt번째 자리에 i 추가

		if (cnt == M)//마지막 자리라면
		{
			int j;
			if (IsAscending() == 0)
			{

			}
			else
			{
				for (j = 1; j <= M; j++)
				{
					printf("%d ", sequence[j]);
				}
				printf("\n");
			}

			//isUsedNumArr[i] = 0;//같은 레벨(동일한 자리)의 수에 대한 재귀가 끝나면
								//그 자리에 다른수가 들어가기 때문에 사용안한것으로 다시바꾼다.
			continue;

		}
		PrintSequenceAll(cnt + 1);// cnt+1 번째 자리에 들어올 수 찾기
		//isUsedNumArr[i] = 0;	//같은 레벨(동일한 자리)의 수에 대한 재귀가 끝나면
								//그 자리에 다른수가 들어가기 때문에 사용안한것으로 다시바꾼다.

	}

}


int main()
{
	scanf("%d %d", &N, &M);

	PrintSequenceAll(1);


	return 0;
}