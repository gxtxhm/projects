//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//typedef struct wordInfo {
//	char word[50];
//	int wordlength;
//}Word;
//
//Word word[20000];
//
//int compare(const void* a, const void* b)    // 오름차순 비교 함수 구현
//{
//	Word num1 = *(Word*)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
//	Word num2 = *(Word*)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
//
//	if (num1.wordlength < num2.wordlength)    // a가 b보다 작을 때는
//		return -1;      // -1 반환
//
//	if (num1.wordlength > num2.wordlength)    // a가 b보다 클 때는
//		return 1;       // 1 반환
//
//	if (num1.wordlength == num2.wordlength)
//	{
//		return strcmp(num1.word, num2.word);
//	}
//
//	return 0;    // a와 b가 같을 때는 0 반환
//}
//
//int main() {
//
//	int N,i;
//
//	scanf("%d", &N);
//	for (i = 0; i < N; i++)
//	{
//		scanf("%s", word[i].word);
//		word[i].wordlength = strlen(word[i].word);
//	}
//
//	qsort(word, N, sizeof(Word), compare);
//
//	for (i = 0; i < N; i++)
//	{
//		//동일한 문자열이면 출력을 안해야하기 때문에 
//		//일단 길이를 비교하여 strcmp함수의 사용을 줄였다. 
//		if(word[i].wordlength!=word[i+1].wordlength)
//			printf("%s\n", word[i].word);
//		//2개의 길이가 같다면
//		else
//		{
//			if(strcmp(word[i].word, word[i+1].word)!=0)
//				printf("%s\n", word[i].word);
//		}
//	}
//
//	return 0;
//}