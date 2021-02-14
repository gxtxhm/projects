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
//int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
//{
//	Point num1 = *(Point*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
//	Point num2 = *(Point*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
//
//	if (num1.y < num2.y)    // a가 b보다 작을 때는
//		return -1;      // -1 반환
//
//	if (num1.y > num2.y)    // a가 b보다 클 때는
//		return 1;       // 1 반환
//
//	if (num1.y == num2.y)
//	{
//		if (num1.x < num2.x)
//			return -1;
//		if (num1.x > num2.x)
//			return 1;
//		return 0;
//	}
//
//	return 0;    // a와 b가 같을 때는 0 반환
//}
//
//int main() {
//
//	int N, i, imsiCnt;
//	Point point[100000];
//
//	scanf("%d", &N);
//
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d %d", &point[i].x, &point[i].y);
//	}
//
//	qsort(point, N, sizeof(Point), compare);
//
//	for (i = 0; i < N; i++)
//	{
//		printf("%d %d\n", point[i].x, point[i].y);
//	}
//
//	return 0;
//}