//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct _point {
//	int x;
//	int y;
//}Point;
//
//
//
//int compare(const void* a, const void* b)    // �������� �� �Լ� ����
//{
//	Point num1 = *(Point*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
//	Point num2 = *(Point*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
//
//	if (num1.x < num2.x)    // a�� b���� ���� ����
//		return -1;      // -1 ��ȯ
//
//	if (num1.x > num2.x)    // a�� b���� Ŭ ����
//		return 1;       // 1 ��ȯ
//
//	if (num1.x == num2.x)
//	{
//		if (num1.y < num2.y)
//			return -1;
//		if (num1.y > num2.y)
//			return 1;
//		return 0;
//	}
//
//	return 0;    // a�� b�� ���� ���� 0 ��ȯ
//}
//
//int main() {
//	
//	int N,i,imsiCnt;
//	Point point[100000];
//	//Point* imsiP;
//	scanf("%d", &N);
//	
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d %d", &point[i].x, &point[i].y);
//	}
//
//	qsort(point, N, sizeof(Point), compare);
//
//	/*for (i = 0; i < N; i++)
//	{
//		imsiCnt = 0;
//		if (point[i].x == point[i + 1].x)
//		{
//			imsiCnt = i;
//			while (!point[i].x == point[i + 1].x)
//			{
//				 i++;
//			}
//			imsiP = (Point*)malloc(sizeof(Point) * (i - imsiCnt));
//		}
//	}*/
//
//	for (i = 0; i < N; i++)
//	{
//		printf("%d %d\n", point[i].x, point[i].y);
//	}
//
//	return 0;
//}