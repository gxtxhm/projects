#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int N;
int operatorNum[4];//������ ����
int Operator[11];//N-1���� ������ ������ �迭������
int Number[12];//���ڹ迭
int checkuseoperator[11];//����ߴ��� üũ

//������ �� ������
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
	checkuseoperator[operatorCnt] = i-1;//operatorCnt��° �����ڴ� i-1��° �����ڰ� ����
	operatorCnt++;

	return j;
}



//�����ڸ� ������� ��Ʈ��ŷ
void FindResult(int on)//on= �迭�� ���°ĭ�� �� ����������
{
	int i;
	if (on == N)
	{
		//��� �� �ִ�,�ּ� ����
	}
	//�����ڴ���
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