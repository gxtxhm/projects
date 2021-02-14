#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int compare(const void* a, const void* b)    // �������� �� �Լ� ����
{
	int num1 = *(int*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
	int num2 = *(int*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������

	if (num1 < num2)    // a�� b���� ���� ����
		return -1;      // -1 ��ȯ

	if (num1 > num2)    // a�� b���� Ŭ ����
		return 1;       // 1 ��ȯ

	return 0;    // a�� b�� ���� ���� 0 ��ȯ
}

int arr[500000] = { 0, };

int main()
{
	int n,i,modeCnt=0;//modeCnt==�ֺ󰪸��°����
	double cnt = 0;//����
	int average = 0;//���
	int arr2[8003] = { 0, };//-4001~4001�������� �󵵼��� ��´�. ������ 4002~8002�δ�ü�Ѵ�.
	int mode1=0, mode2=0;//mode1 == �ֺ��� �󵵼�, mode2�� �ֺ�

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		//���� ����
		//���հ�� �� �󵵼� ������Ű��
		if (arr[i] < 0)
			arr2[arr[i]*-1 + 4001]++;
		else
			arr2[arr[i]]++;
		cnt += arr[i];
	}
	//������
	qsort(arr, n, sizeof(int), compare);

	//����,��� �ݿø� ó��
	if (cnt < 0)
	{
		average = (int)(cnt / n - 0.5);
	}
	else
	{
		average = (int)(cnt / n + 0.5);
	}
	
	//������
	printf("%d\n", average);
	//�߰���
	printf("%d\n", arr[n / 2]);
	//�ֺ�
	//������������ ����������� ������� Ȯ���Ѵ�.
	//��������
	for (i = 8002; i >= 4002; i--)
	{
		//���� ������� �󵵼����� ���� �󵵼��� ������
		if (mode1 < arr2[i])
		{
			modeCnt = 1;//���� ���� �ֺ�
			mode2 = (i - 4001) * -1;
			if (modeCnt != 2)//�ι�° �ֺ��� �����ϱ� �����̴�.
			{
				mode1 = arr2[i];
			}
		}
		//������ �󵵼��̸鼭 �ι�°�� ���� �ֺ��̶��
		else if (mode1 == arr2[i] && modeCnt < 2)
		{
			modeCnt++;

			mode2 = (i - 4001) * -1;
		}
	}
	//�������
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
	//����
	printf("%d\n", arr[n - 1] - arr[0]);
	return 0;
}