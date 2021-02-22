#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int N;
int operatorNum[4];//연산자 개수
int Operator[11];//N-1개의 연산자 순서를 배열로저장
int Number[12];//숫자배열
int checkuseoperator[11];//사용했는지 체크

//다음에 올 연산자
int NextOperator(int operatorCnt)
{
	int j = 0,i;
	for ( i = 0; i <= operatorCnt; i++)
	{
		
		if (operatorNum[j] == i)
		{
			j++; i--;
		}
		
	}
	if (checkuseoperator[i] == j)
		return -1;
	checkuseoperator[operatorCnt] = i-1;//operatorCnt번째 연산자는 i-1번째 연산자가 쓰임
	operatorCnt++;

	return j;
}



//연산자를 대상으로 백트래킹
void FindResult(int on)//on= 배열의 몇번째칸에 들어갈 연산자인지
{
	int i;
	if (on == N)
	{
		//계산 후 최대,최소 갱신
	}
	//연산자대입
	for (i = 1; i <= N - 1; i++)
	{
		int n = NextOperator(on);
		if (n != -1)
		{
			Operator[on] = n;
			FindResult(on + 1);
		}
		for (i = 1; i <= N - 1; i++)
		{
			printf("%d ", Operator[i]);
		}
		printf("\n\n");
	}

}

int main()
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		scanf("%d", &Number[i]);
	}

	for (i = 0; i < 4; i++)
	{
		scanf("%d", &operatorNum[i]);
	}
	FindResult(0);

	return 0;
}