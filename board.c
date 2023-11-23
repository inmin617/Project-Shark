#include <stdio.h>
#include <stdlib.h>
#include "board.h"

#define N_BOARD   15
#define BOARDSTATUS_OK   1
#define BOARDSTATUS_NOK   0
#define N_COINPOS  12
#define MAX_COIN  4

static int board_status[N_BOARD];//?????? 
static int board_coin[N_BOARD];//????? ??????? 

//??????
//static int board_sharkPosition; //data incapsulation 

//???????? 
int board_initBoard(void)
{
	int i;
	for(i=0;i<N_BOARD;i++)
	{
		board_status[i] = BOARDSTATUS_OK;
		board_coin[i] = 0;
	 } //???????????? 
	//???? ??? 
	for(i=0;i<N_COINPOS;i++)
	{
		int flag = 0; 
		while(flag == 0)
		{
			//???????? ? ????????
			int allocpos = rand()%N_BOARD;
			//??? ??????????
			if(board_coin[allocpos] == 0)
			{
				board_coin[allocpos] = rand()%MAX_COIN+1;//1????4 
				
				flag = 1;
			}
			
		}
	}
	return 0; 
}

//??u???? ???? ???
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

//???? ???? ????
int board_getBoardCoin(int pos)
{
	int coin = board_coin[pos]; //?????????? 
	board_coin[pos] = 0; //??????? ?????? 
	
	return coin; //??????0?? ?????-??????????? ??????????
}

//??? ??? ???
int board_sharkposition(void);

//??? ???? ????
int board_moveshark(void);

//??? ??? ??? ???? ???
int board_getBoardStatus(int pos)
{
	return board_status[pos]; //????u?? ?????? 0,1 
}
