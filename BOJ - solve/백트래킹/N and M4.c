#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int isUsedNumArr[9] = { 0, };//����� ���ڴ� 1, �̻���� ���ڴ� 0
int sequence[9] = { 0, };//������ ����� �� �߿��� 1���� ����ȴ�.
int N;//����� �ڿ����� ���� 1���� ����
int M;//N���� �ڿ��� �߿��� M���� ��� ������ �����.

int IsAscending()//���������ΰ� üũ���ִ� �Լ�
{
	int i;
	for (i = 1; i < M; i++)
	{
		if (sequence[i] > sequence[i + 1])
			return 0;
	}
	return 1;
}
void PrintSequenceAll(int cnt)//��� ����� ������ ���
{
	int i;
	//cnt��° �ڸ��� �� �� ã��
	for (i = 1; i <= N; i++)
	{


		sequence[cnt] = i;//������ cnt��° �ڸ��� i �߰�

		if (cnt == M)//������ �ڸ����
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

			//isUsedNumArr[i] = 0;//���� ����(������ �ڸ�)�� ���� ���� ��Ͱ� ������
								//�� �ڸ��� �ٸ����� ���� ������ �����Ѱ����� �ٽùٲ۴�.
			continue;

		}
		PrintSequenceAll(cnt + 1);// cnt+1 ��° �ڸ��� ���� �� ã��
		//isUsedNumArr[i] = 0;	//���� ����(������ �ڸ�)�� ���� ���� ��Ͱ� ������
								//�� �ڸ��� �ٸ����� ���� ������ �����Ѱ����� �ٽùٲ۴�.

	}

}


int main()
{
	scanf("%d %d", &N, &M);

	PrintSequenceAll(1);


	return 0;
}