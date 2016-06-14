#pragma once
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#include "ScreenOut.h"
#include "Stage_Info.h"
#include "Mangchi.h"
#include "dudagi.h"

#include "Heart_Screen.h"
#include "Heart_Stage.h"

#define BOUNDARY_MIN 2
#define BOUNDARY_MAX 43

typedef enum _GAME_STATE { INIT, READY, RUNNING, SUCCESS, FAILED, STOP, RESULT } GAME_STATE;
GAME_STATE		g_nGameState = INIT;

int				g_nStage = -1;
int				g_nGrade = 0; // Á¡¼ö 
int				g_nTotalGrade = 0; // ÃÑÁ¡
clock_t			g_GameStartTime, g_UpdateOldTime, g_RemainTime;
int g_nHeartDownCount = 0;
int g_nHeartCount; // È¹µæÇÑ ÇÏÆ® °³¼ö
int g_nDeadHeartCount = 0;	// Á×Àº ÇÏÆ® °³¼ö

ScreenAll ScreenA;
StageAll g_sStageInfo;

typedef struct _XY
{
	int nX, nY;
} XY;

XY	g_Point[9] = { { 10, 15 }, { 20, 15 }, { 30, 15 },
{ 10, 10 }, { 20, 10 }, { 30, 10 },
{ 10, 5 }, { 20, 5 }, { 30, 5 }
};

dStage_Info g_StageInfo[3] = { { 2, 1000 * 10, 6000, 4000 }, { 5, 1000 * 10, 2000, 2000 },
{ 50, 1000 * 120, 1000, 1000 } };
int         g_nIsSuccess = 0;

Dudagi	g_Dudagi[9];
Mangchi	g_Mangchi;
dScreenOut dscreen;
int			g_nStageCount = 1;
int			g_nDudagiCount = 0;

class AllMain{
public:
	AllMain();

	void hInit();
	void hUpdate();
	void hRender();
	void hRelease();
	void dInit();
	void dUpdate();
	void dRender();
	void hMain();
	void dMain();
};

