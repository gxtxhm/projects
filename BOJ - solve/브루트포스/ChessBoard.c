//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//char Board[50][50];
//char imsiBoard[8][8];
//char imsi2[8][8];
//void CopyBoard(int n,int m)
//{
//	int i, j;
//
//	for (i = n; i < n + 8; i++)
//	{
//		for (j = m; j < m + 8; j++)
//		{
//			imsiBoard[i - n][j - m] = Board[i][j];
//			imsi2[i - n][j - m] = Board[i][j];
//		}
//	}
//}
//
//
//int compSetBoard()
//{
//	int changeNum1 = 0, changeNum2 = 0;
//	int i, j;
//	
//	//처음이 흰색일때
//	if(imsiBoard[0][0] == 'W'){ imsiBoard[0][0] = 'W'; }
//	else
//	{
//		imsiBoard[0][0] = 'W';
//		changeNum1++;
//	}
//	
//
//	for (i = 0; i < 8; i++)
//	{
//		for (j = 0; j < 8; j++)
//		{
//			if (i == 0 && j == 0)continue;
//			//왼쪽에꺼랑 값이 같다면
//			if (j != 0)
//			{
//				if (imsiBoard[i][j] == imsiBoard[i][j - 1])
//				{
//					if (imsiBoard[i][j] == 'W')
//						imsiBoard[i][j] = 'B';
//					else
//						imsiBoard[i][j] = 'W';
//
//					changeNum1++;
//				}
//			}
//			//위쪽이랑 값이 같다면
//			if (i != 0)
//			{
//				if (imsiBoard[i][j] == imsiBoard[i - 1][j])
//				{
//					if (imsiBoard[i][j] == 'W')
//						imsiBoard[i][j] = 'B';
//					else
//						imsiBoard[i][j] = 'W';
//					
//					changeNum1++;
//				}
//			}
//		}
//	}
//
//	//처음이 검은색일때
//	if (imsi2[0][0] == 'B') { imsi2[0][0] = 'B'; }
//	else
//	{
//		imsi2[0][0] = 'B';
//		changeNum2++;
//	}
//
//	for (i = 0; i < 8; i++)
//	{
//		for (j = 0; j < 8; j++)
//		{
//			if (i == 0 && j == 0)continue;
//			//왼쪽에꺼랑 값이 같다면
//			if (j != 0)
//			{
//				if (imsi2[i][j] == imsi2[i][j - 1])
//				{
//					if (imsi2[i][j] == 'W')
//						imsi2[i][j] = 'B';
//					else
//						imsi2[i][j] = 'W';
//					
//					changeNum2++;
//				}
//			}
//			//위쪽이랑 값이 같다면
//			if (i != 0)
//			{
//				if (imsi2[i][j] == imsi2[i - 1][j])
//				{
//					if (imsi2[i][j] == 'W')
//						imsi2[i][j] = 'B';
//					else
//						imsi2[i][j] = 'W';
//					
//					changeNum2++;
//				}
//			}
//		}
//	}
//	if (changeNum1 < changeNum2)
//		return changeNum1;
//	else
//		return changeNum2;
//}
//
//
//int main()
//{
//	int N, M;//N은 행, M은 열
//	int i,j;
//	int Num = 0;
//	int result;
//
//	scanf("%d %d", &N, &M);
//	for (i = 0; i < N; i++)
//	{
//		scanf("%s", Board[i]);
//	}
//	
//	for (i = 0; i < N - 7; i++)
//	{
//		for (j = 0; j < M - 7; j++)
//		{
//			CopyBoard(i, j);
//			result= compSetBoard();
//			if (i == 0 && j == 0)
//				Num = result;
//			else
//			{
//				if(Num > result)
//					Num= result;
//			}
//		}
//	}
//	
//
//	
//		printf("%d", Num);
//	
//
//	return 0;
//}