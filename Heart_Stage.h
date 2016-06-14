#pragma once
#include <time.h>

typedef struct _STAGE
{
	int nBasketX;                  // Note: 하트 바구니의 x 좌표
	int nBasketY;	              // Note: 하트 바구니의 y 좌표	
	int nHeartCount;	              // Note: Stage별 총 하트 수
	int nGoalHeartCount;	          // Note: 목표 하트 수
	int nBarLength;	              // Note: 막대기길이
	clock_t BasketMoveTime;        // Note: 하트 바구니가 움직이는 이동 시간 간격
	clock_t BasketDownHeartTime;   // Note: 하트가 떨어지는 시간 간격
} STAGE;

class StageAll
{
public:
	int nStageCount;
	STAGE *pStage;
};