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
//int compare(const void* a, const void* b)    // �������� �� �Լ� ����
//{
//	Word num1 = *(Word*)a;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
//	Word num2 = *(Word*)b;    // void �����͸� int �����ͷ� ��ȯ�� �� �������Ͽ� ���� ������
//
//	if (num1.wordlength < num2.wordlength)    // a�� b���� ���� ����
//		return -1;      // -1 ��ȯ
//
//	if (num1.wordlength > num2.wordlength)    // a�� b���� Ŭ ����
//		return 1;       // 1 ��ȯ
//
//	if (num1.wordlength == num2.wordlength)
//	{
//		return strcmp(num1.word, num2.word);
//	}
//
//	return 0;    // a�� b�� ���� ���� 0 ��ȯ
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
//		//������ ���ڿ��̸� ����� ���ؾ��ϱ� ������ 
//		//�ϴ� ���̸� ���Ͽ� strcmp�Լ��� ����� �ٿ���. 
//		if(word[i].wordlength!=word[i+1].wordlength)
//			printf("%s\n", word[i].word);
//		//2���� ���̰� ���ٸ�
//		else
//		{
//			if(strcmp(word[i].word, word[i+1].word)!=0)
//				printf("%s\n", word[i].word);
//		}
//	}
//
//	return 0;
//}