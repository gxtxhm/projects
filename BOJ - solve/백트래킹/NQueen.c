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
//			queen[x] = i;//x행에 i열에 퀸 배치
//			if (IsPosible(x))//x행 i열에 놓는게 가능하냐?
//			{
//				findNQueen(x + 1);//가능하면 다음꺼 배치
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
