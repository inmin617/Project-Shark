#include <stdio.h>
#include <stdlib.h>
#define BOARDSTATUS_OK   1
#define BOARDSTATUS_NOK   0 //메인함수에 알려야함 
#define N_BOARD   15

//보드초기화 
int board_initBoard(void);

//전체보드 상태 출력 
int board_printBoardStatus(void);

//동전 습득 명령 
int board_getBoardCoin(int pos);

//상어 위치 출력 
int board_sharkposition(void);

//상어 전진 명령 
int board_moveshark(void);

//특정 칸의 파손 여부 출력 
int board_getBoardStatus(int pos);
