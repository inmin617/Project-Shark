#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_BOARD   15
#define BOARDSTATUS_OK	1
#define BOARDSTATUS_NOK	0
#define N_COINPOS	12
#define MAX_COIN	4

#define MAX-SHARKSTEP	6
#define SHARK_INITPOS	-4

static int board_status[N_BOARD];//파손여부 
static int board_coin[N_BOARD];//칸마다 코인개수 
static int board_sharkPosition;

//상어위치 
//static int board_sharkPosition; //data incapsulation 

//보드초기화 
int board_initBoard(void)
{
	int i;
	for(i=0;i<N_BOARD;i++)
	{
		board_status[i] = BOARDSTATUS_OK;
		board_coin[i] = 0;
	 } //전역변수초기화 
	 
	 board_sharkPosition=SHARKPOSITION;
	//코인 할당 
	for(i=0;i<N_COINPOS;i++)
	{
		int flag = 0; 
		while(flag == 0)
		{
			//동전놓을 칸 랜덤지정 
			int allocpos = rand()%N_BOARD;
			//칸에 동전없으면 
			if(board_coin[allocpos] == 0)
			{
				board_coin[allocpos] = rand()%MAX_COIN+1;//1????4 
				
				flag = 1;
			}
			
		}
	}
	return 0; 
}

//전체보드 상태 출력 
int board_printBoardStatus(void)
{
	int i;
	printf("-----------------BOARD STATUS-------------------\n");
	for(i=0;i<N_BOARD;i++)
	{
		printf("|");
		if(board_status[i] == BOARDSTATUS_NOK)
		 printf("X");
		else
		 printf("O");
	}
	printf("|\n");
	printf("-----------------------------------------------\n");
	
	return 0;
}

//동전 습득 명령 
int board_getBoardCoin(int pos)
{
	int coin = board_coin[pos]; //동전몇개였어 
	board_coin[pos] = 0; //한번주우면 없어짐 
	
	return coin; //무조건 0이 반환됨-지역변수필요????? 
}

int board_stepShark(void)
{
	int step=rand()&MAX_SHARKSTEP+1;
	int i;
	for(i=shark_position+1; i<=shark_position+step; i++)
	{
		if (i>=0 && i<N_BOARD)
			board_status[i]=BOARDSTATUS_NOK;
		
	}
	
	shark_position+=step;
	return shark_position; 
}

//상어 위치 출력 
int board_sharkposition(void);

//상어 전진 명령 
int board_moveshark(void);

//특정 칸의 파손 여부 출력 
int board_getBoardStatus(int pos)
{
	return board_status[pos]; //값자체를 내보냄 0,1 
}
