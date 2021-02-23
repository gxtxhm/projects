//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//
//int N;
//int numArr[11];//최대 11개의 수를 저장할 숫자 배열
//int operatorNum[4];//각 연산자가 몇개씩 사용되는지
//
//int imsiNumArr[11];//계산시마다 원본에서 복사할 숫자 배열
//int operatorEarly[10];//N-1개의 연산자를 입력순서대로 나열한 배열-백트래킹에 사용
//int visited[10];//사용한 연산자인가
//
//int operatorArr[10];//N-1개로 만들어질 연산자배열의 경우
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
//			//if (imsiNumArr[i - 1] < 0)//c++14의 기준따르기
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
//	if (cnt == N-1)//경우의수 완성
//	{
//		int res= result();
//		if (res > max)//최대를 갱신하면
//			max = res;
//		if(res < min)//최소를 갱신하면
//			min = res;
//	
//		
//		return;
//	}
//
//	for (int i = 0; i < N-1; i++)//N-1번 반복 모든 연산자를 대상으로 경우의수 만들기 시도
//	{
//		if (visited[i] == 0)//사용안된 연산자면
//		{
//			visited[i] = 1;//방문표시
//			operatorArr[cnt] = operatorEarly[i];//cnt번째 연산자로 operatorEarly[i]를 대입
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
//		for (int j = 0; j < operatorNum[i]; j++)//operatorEarly배열에 사칙연산자들을 순서대로 대입
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