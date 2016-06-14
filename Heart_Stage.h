#pragma once
#include <time.h>

typedef struct _STAGE
{
	int nBasketX;                  // Note: ��Ʈ �ٱ����� x ��ǥ
	int nBasketY;	              // Note: ��Ʈ �ٱ����� y ��ǥ	
	int nHeartCount;	              // Note: Stage�� �� ��Ʈ ��
	int nGoalHeartCount;	          // Note: ��ǥ ��Ʈ ��
	int nBarLength;	              // Note: ��������
	clock_t BasketMoveTime;        // Note: ��Ʈ �ٱ��ϰ� �����̴� �̵� �ð� ����
	clock_t BasketDownHeartTime;   // Note: ��Ʈ�� �������� �ð� ����
} STAGE;

class StageAll
{
public:
	int nStageCount;
	STAGE *pStage;
};