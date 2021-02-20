#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int board[9][9];
int empty[100][3];
int emptyNum = 0;
int isFinish = 0;

int IsPosible(int eN,int Num)
{
	int x = empty[eN][0];
	int y = empty[eN][1];
	int startX=0, endX=0, startY=0, endY=0;
	for (int i = 0; i < 9; i++)
	{
		if (board[x][i] == Num)
			return 0;
		if (board[i][y] == Num)
			return 0;
	}
	switch (empty[eN][2])
	{
	case 0:
		startX = 0; endX = 2; startY = 0; endY = 2; break;
	case 1:
		startX = 0; endX = 2; startY = 3; endY = 5; break;
	case 2:
		startX = 0; endX = 2; startY = 6; endY = 8; break;
	case 3:
		startX = 3; endX = 5; startY = 0; endY = 2; break;
	case 4:
		startX = 3; endX = 5; startY = 3; endY = 5; break;
	case 5:
		startX = 3; endX = 5; startY = 6; endY = 8; break;
	case 6:
		startX = 6; endX = 8; startY = 0; endY = 2; break;
	case 7:
		startX = 6; endX = 8; startY = 3; endY = 5; break;
	case 8:
		startX = 6; endX = 8; startY = 6; endY = 8; break;
	default:
		break;
	}
	
	for (int i = startX; i <= endX; i++)
	{
		for (int j = startY; j <= endY; j++)
		{
			if (empty[eN][0] == i && empty[eN][1] == j)continue;
			if (board[i][j] == Num)
				return 0;
		}
	}

	return 1;
}


void sdoku(int eN)//eN = emptyNum
{
	if (isFinish == 1)
		return;
	if (eN == emptyNum)//������ Ǭ ��
	{
		isFinish = 1;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (IsPosible(eN, i))//eN��° ��ĭ�� i�� �� �� �ֳ�?
		{
			board[empty[eN][0]][empty[eN][1]] = i;
			sdoku(eN + 1); 
			//��ĭ�� ���� �������� �ڿ��� ó���� �ȵǾ��µ� ������ 
			//�ؿ� 2���� �ڵ尡 ������ �����ΰŰ���.
			//��Ʈ��ŷ�� ���� ������ ���鼭 ����Ǽ��� ������ ������ 
			//���ٰ� ���Դٸ� �ٽ� �湮���� ���·� �ǵ����� �Ѵ�.
			if(isFinish==0)
				board[empty[eN][0]][empty[eN][1]] = 0;
		}
	}
	
}

void findEmpty()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				empty[emptyNum][0] = i;
				empty[emptyNum][1] = j;
				switch (i/3)
				{
					case 0:
						if (j / 3 == 0)
							empty[emptyNum][2] = 0;
						else if(j/3==1)
							empty[emptyNum][2] = 1;
						else
							empty[emptyNum][2] = 2; break;
					case 1:
						if (j /3 == 0)
							empty[emptyNum][2] = 3;
						else if (j / 3 == 1)
							empty[emptyNum][2] = 4;
						else
							empty[emptyNum][2] = 5; break;
					case 2:
						if (j / 3 == 0)
							empty[emptyNum][2] = 6;
						else if (j / 3 == 1)
							empty[emptyNum][2] = 7;
						else
							empty[emptyNum][2] = 8; break;

					default:
					break;
				}
				emptyNum++;
			}

		}
	}
}

int main() {

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			scanf("%d", &board[i][j]);
	findEmpty();
	
	sdoku(0);
	printf("\n\n");
	for (int a = 0; a < 9; a++)
	{
		for (int b = 0; b < 9; b++)
			printf("%d ", board[a][b]);

		printf("\n");
	}
	return 0;
}
