//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int N;
//int numArr[11];//�ִ� 11���� ���� ������ ���� �迭
//int operatorNum[4];//�� �����ڰ� ��� ���Ǵ���
//
//int imsiNumArr[11];//���ø��� �������� ������ ���� �迭
//int operatorEarly[10];//N-1���� �����ڸ� �Է¼������ ������ �迭-��Ʈ��ŷ�� ���
//int visited[10];//����� �������ΰ�
//
//int operatorArr[10];//N-1���� ������� �����ڹ迭�� ���
//
//int max=-1000000000, min= 1000000000;
//
//int result()
//{
//	for (int i = 0; i < N; i++)
//		imsiNumArr[i] = numArr[i];
//
//	for (int i = 1; i < N; i++)
//	{
//		switch (operatorArr[i-1])
//		{
//		case 1:
//			imsiNumArr[i] = imsiNumArr[i - 1] + imsiNumArr[i]; break;
//		case 2:
//			imsiNumArr[i] = imsiNumArr[i - 1] - imsiNumArr[i]; break;
//		case 3:
//			imsiNumArr[i] = imsiNumArr[i - 1] * imsiNumArr[i]; break;
//		case 4:
//			//if (imsiNumArr[i - 1] < 0)//c++14�� ���ص�����
//			//	imsiNumArr[i - 1] *= -1;
//			//if (imsiNumArr[i] < 0)
//			//	imsiNumArr[i] *= -1;
//			imsiNumArr[i] = imsiNumArr[i - 1] / imsiNumArr[i];
//			
//			break;
//		default:
//			break;
//		}
//
//	}
//	return imsiNumArr[N - 1];
//}
//
//
//void BackTracking(int cnt)
//{
//	if (cnt == N-1)//����Ǽ� �ϼ�
//	{
//		int res= result();
//		if (res > max)//�ִ븦 �����ϸ�
//			max = res;
//		if(res < min)//�ּҸ� �����ϸ�
//			min = res;
//	
//		
//		return;
//	}
//
//	for (int i = 0; i < N-1; i++)//N-1�� �ݺ� ��� �����ڸ� ������� ����Ǽ� ����� �õ�
//	{
//		if (visited[i] == 0)//���ȵ� �����ڸ�
//		{
//			visited[i] = 1;//�湮ǥ��
//			operatorArr[cnt] = operatorEarly[i];//cnt��° �����ڷ� operatorEarly[i]�� ����
//			BackTracking(cnt+1);
//			visited[i] = 0;
//		}
//		
//	}
//}
//
//
//
//int main()
//{
//	int i,oCnt=0;
//	scanf("%d", &N);
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d", &numArr[i]);
//	}
//	for (i = 0; i < 4; i++)
//	{
//		scanf("%d", &operatorNum[i]);
//		for (int j = 0; j < operatorNum[i]; j++)//operatorEarly�迭�� ��Ģ�����ڵ��� ������� ����
//		{
//			operatorEarly[oCnt] = i + 1;
//			oCnt++;
//		}
//	}
//	BackTracking(0);
//	
//	printf("%d %d", max, min);
//
//	return 0;
//}