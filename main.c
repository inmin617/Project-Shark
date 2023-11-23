#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"

#define N_PLAYER	5
#define MAX_DIE	6

#define PLAYERSTATUS_LIVE	0
#define PLAYERSTATUS_DIE	1
#define PLAYERSTATUS_END	2

int player_position[N_PLAYER];
char player_name[N_PLAYER][MAX_CHARNAME];
int player_coin[N_PLAYER];
int player_status[N_PLAYER];
char player_statusString[3][MAX_CHARNAME] = ("LIVE", "DIE", "END");

void opening(void)
{
	printf("=============WELCOME=============\n");
	printf("============SHARK_GAME===========\n");
	printf("==============START==============\n");
}

int rolldie(void)
{
	return rand()%MAX_DIE+1;
}

void printfPlayerPosition(int player){
	int i;
	for(i=0; i<N_BOARD; i++)
	{
		printf("|");
		if (i==player_position[player])
			printf("%c", player_name[player][0]);
		
		else{
			if (board_getBoardStatus(i)==BOARDSTATUS_NOK)
				printf("X");
			else
				printf(" ");
		}
	}
	printf("|\n");
}

void printPlayerStatus(void)
{
	int i;
	for(i=0; i<N_PLAYER; i++)
	{
		printf("%s: pos %I, coin %i, status: %s\n", player_name[], player_position[i], player_statusString[player_status[i]]);
	}
}
int main(int argc, char *argv[]) {
	
	int pos = 0;
	srand((unsigned)time(NULL));
	
	//0.opening
	opening();
	
	//1.�ʱ�ȭ, �÷��̾� �̸� 
	board_initBoard();
	
	//2.�ݺ���(�� �÷��̾� ��) 
	for (i=0; i<N_PLAYER; i++){
		player_position[i]=0;
		player_coin[i]=0;
		player_status[i]=PLAYERSTATUS_LIVE;
		//player_name
		printf("Player %i's name:", i);
		scanf("%s", player_name[i]);
	}
	
	do{
		int step = rolldie();
		int coinResult;
		char c;
		
		board_printBoardStatus();
		
		pos += step;
		//printf()
		coinResult = board_getBoardCoin(pos);
		
		printf("Press any key to continue:");
		scanf("%d", &c);
		fflush(stdin);
		
		//2.1. ������� 
		board_printBoardStatus();
		for (i=0;i<N_PLAYER; i++)
			printPlayerPosition(turn);
		printfPlayerStatus();
		
		//2.2.�ֻ��������� 
		printf("%s turn!!", player_name[turn]);
		printf("press any key to roll a die!\n");
		scanf("%d, &c");
		fflush(stdin);
		step=rolldie();
	
		//2.3.�̵� 
		player_position[turn]+=step;
		if (player_position[turn] >= N_BOARD)
			player_position[turn]=N_BOARD-1;
		printf()
		
		//2.4.���ξ�� 
		cointResult=board_getBoardCoin(pos);
		
		//2.5.������ 
		turn=(turn+1);%N_PLAYER; // wrap around 
		//2.6.����(����: ����÷��̾� �ѹ��� �� ������) 
	}while(1);
	
	//3.���� ��(���ڰ��, ���) 
	return 0;
}
