//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int N;
//int cnt = 0;
//int queen[15] = { 0, };
//
//
//int IsPosible(int x)
//{
//	for (int i = 0; i < x; i++)
//	{
//		if (queen[i] == queen[x])
//			return 0;
//
//		if (x - i == abs(queen[i] - queen[x]))
//			return 0;
//	}
//	return 1;
//}
//
//void findNQueen(int x)
//{
//	if (x == N)
//	{
//		cnt++;
//	}
//	else
//	{
//		for (int i = 0; i < N; i++)
//		{
//			queen[x] = i;//x�࿡ i���� �� ��ġ
//			if (IsPosible(x))//x�� i���� ���°� �����ϳ�?
//			{
//				findNQueen(x + 1);//�����ϸ� ������ ��ġ
//			}
//		}
//	}
//}
//
//
//
//int main() {
//	
//	scanf("%d", &N);
//	findNQueen(0);
//	printf("%d", cnt);
//	return 0;
//}
