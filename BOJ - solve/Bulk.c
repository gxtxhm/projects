//백준 - 덩치문제
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct _people {
	int height;
	int weight;
	int rank;
}People;

People people[50];


int main() {
	
	int num,i,j;
	int w, h;
	scanf("%d", &num);
	
	for (i = 0; i < num; i++) {
		scanf("%d %d", &(people[i].weight), &(people[i].height));
		people[i].rank = 1;
	}
	
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if ((people[i].height < people[j].height) && (people[i].weight < people[j].weight))
			{
				people[i].rank++;
			}
		}
	}

	for (i = 0; i < num; i++) {
		printf("%d ", people[i].rank);
	}

	return 0;
}