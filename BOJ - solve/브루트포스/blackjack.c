#include<stdio.h>


int blackJack() {

	int n, m;
	int cards[100] = {0,};
	int maxSum = 0, cntSum = 0;
	int i, j, k;
	scanf_s("%d %d", &n, &m);

	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &cards[i]);
	}
	

	for (i = 0; i < n-2; i++)
	{
		for (j = i+1; j < n-1; j++)
		{
			for (k = j+1; k < n; k++)
			{	
					cntSum = cards[i] + cards[j] + cards[k];
					if (cntSum <= m && maxSum < cntSum)
						maxSum = cntSum;
			}
		}
	}
	
	

	printf("%d", maxSum);
	return 0;
}