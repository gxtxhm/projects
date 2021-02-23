#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//처음 입력시 필요
int S[20][20];//선수 간 케미
int N;

//백트래킹시 필요 
int playerArr[20];//하나의 완성된 경우의 수 ,두 팀을 가운데 기준으로 앞,뒤로 나눔
int visit[20];//선수가 뽑혔나 체크

int min=1000000;

int DiffStartAndLink()//스타트팀과 링크팀의 전력차
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
	if (cnt == N/2)//하나의 경우의 수가 완성되면
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
		
		//계산하기
		if (res < min)
			min = res;
		
		return;
	}
	for (int i = 0; i < N; i++)
	{
			if (visit[i] == 0&& (cnt == 0 || playerArr[cnt - 1] < i))//cnt번째자리에 i가 뽑히지 않은 선수라면
			{										//두번째 조건은 경우를 오름차순으로만 만든다.
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