#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//ó�� �Է½� �ʿ�
int S[20][20];//���� �� �ɹ�
int N;

//��Ʈ��ŷ�� �ʿ� 
int playerArr[20];//�ϳ��� �ϼ��� ����� �� ,�� ���� ��� �������� ��,�ڷ� ����
int visit[20];//������ ������ üũ

int min=1000000;

int DiffStartAndLink()//��ŸƮ���� ��ũ���� ������
{
	int startTeam = 0;
	int linkTeam = 0;
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < N / 2; j++)
		{
			startTeam += S[playerArr[i]][playerArr[j]];
		}
	}
	for (int i = N/2; i < N; i++)
	{
		for (int j = N/2; j < N; j++)
		{
			linkTeam += S[playerArr[i]][playerArr[j]];
		}
	}
	if (startTeam - linkTeam < 0)
		return (linkTeam - startTeam);
	else
		return startTeam - linkTeam;
}


void BackTracking(int cnt)
{
	if (cnt == N/2)//�ϳ��� ����� ���� �ϼ��Ǹ�
	{
		int imsi = cnt;
		
		for (int i = 0; i < N; i++)
		{
			if (visit[i] == 0)
			{
				playerArr[imsi] = i;
				imsi++;
			}
		}
		int res = DiffStartAndLink();
		
		//����ϱ�
		if (res < min)
			min = res;
		
		return;
	}
	for (int i = 0; i < N; i++)
	{
			if (visit[i] == 0&& (cnt == 0 || playerArr[cnt - 1] < i))//cnt��°�ڸ��� i�� ������ ���� �������
			{										//�ι�° ������ ��츦 �����������θ� �����.
				visit[i] = 1;
				playerArr[cnt] = i;
				BackTracking(cnt + 1);
				visit[i] = 0;
			}
	}
}

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &S[i][j]);
		}
	
	BackTracking(0);
	printf("%d", min);
	return 0;
}