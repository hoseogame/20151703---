#include "Heart_Header.h"

int main()
{ 
	AllMain Allmain;
	
	return 0;
}

AllMain::AllMain()
{
	int k = 0;
	printf("게임을 선택해주세요. 1=두더지. 2=하트");
	scanf("%d", &k);
	if (k == 1)
	{
		dMain();
	}
	else if (k == 2)
	{
		hMain();
	}
}

typedef struct _BAR
{
	int nBarLength;	// Note: 막대기 길이
	int nX[7], nY;	// Note: 좌표     
	clock_t  MoveTime;
	clock_t  OldMoveTime;
} BAR;

typedef struct _BASKET
{
	int nX, nY;
	int nDist;
	clock_t OldMoveTime;
	clock_t MoveTime;
	clock_t OldDownHeartTime;
	clock_t DownHeartTime;
} BASKET;

typedef struct _HEART
{
	int nLife;	           // 생명
	int nX, nY;	 // 좌표
	int nDist;            // 이동거리
	clock_t MoveTime;   // 이동 시간 간격 
	clock_t OldMoveTime;     // 이전 이동 시각
} HEART;

BAR g_Bar;
BASKET g_sBasket;
HEART  g_sHeart[100];

void AllMain::hInit()
{
	int i;
	FILE *fp;

	if (g_nStage == -1) // 1번만 초기화가 되는 부분에 대한 처리 사항
	{
		g_nStage = 0;

		//스테이지 설정
		fp = fopen("stage.txt", "r");
		fscanf(fp, "%d\n", &g_sStageInfo.nStageCount);
		g_sStageInfo.pStage = (STAGE*)malloc(sizeof(STAGE) * g_sStageInfo.nStageCount);

		for (i = 0; i < g_sStageInfo.nStageCount; i++)
		{
			fscanf(fp, "%d %d %d %d %d %d %d\n", &g_sStageInfo.pStage[i].BasketMoveTime,
				&g_sStageInfo.pStage[i].BasketDownHeartTime,
				&g_sStageInfo.pStage[i].nBasketX,
				&g_sStageInfo.pStage[i].nBasketY,
				&g_sStageInfo.pStage[i].nHeartCount,
				&g_sStageInfo.pStage[i].nGoalHeartCount,
				&g_sStageInfo.pStage[i].nBarLength);
		}

		fclose(fp);
	}

	g_nGrade = 0;

	// Note: 막대기 초기화      	 
	g_Bar.nY = 22;
	g_Bar.nBarLength = g_sStageInfo.pStage[g_nStage].nBarLength; // 막대기의 길이 
	g_Bar.OldMoveTime = clock();
	g_Bar.MoveTime = 40;

	for (i = 0; i < g_Bar.nBarLength; i++)
	{
		g_Bar.nX[i] = 10 + 2 * (i + 1); // 15 컬럼부터		
	}

	// Note: 하트 바구니 초기화
	g_sBasket.nX = g_sStageInfo.pStage[g_nStage].nBasketX;
	g_sBasket.nY = g_sStageInfo.pStage[g_nStage].nBasketY;
	g_sBasket.OldMoveTime = clock();
	g_sBasket.MoveTime = g_sStageInfo.pStage[g_nStage].BasketMoveTime;
	g_sBasket.DownHeartTime = g_sStageInfo.pStage[g_nStage].BasketDownHeartTime;
	g_sBasket.OldDownHeartTime = clock();
	g_sBasket.nDist = 1;
	g_nHeartDownCount = 0;
	g_nDeadHeartCount = 0;
	g_nHeartCount = 0;
}

void AllMain::hUpdate()
{
	int i, nLength;
	clock_t CurTime = clock();

	switch (g_nGameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 3000)  // 2초
		{
			g_nGameState = RUNNING;
			g_GameStartTime = CurTime;
		}
		break;

	case RUNNING:
		if (g_nDeadHeartCount == g_sStageInfo.pStage[g_nStage].nHeartCount)
		{
			g_nGameState = STOP;
			return;
		}

		if ((CurTime - g_sBasket.OldMoveTime) > g_sBasket.MoveTime)
		{
			g_sBasket.OldMoveTime = CurTime;
			g_sBasket.nX += g_sBasket.nDist;

			if (g_sBasket.nX == BOUNDARY_MIN || g_sBasket.nX + 1 == BOUNDARY_MAX)
				g_sBasket.nDist = -1 * g_sBasket.nDist;
		}

		if (g_nHeartDownCount < g_sStageInfo.pStage[g_nStage].nHeartCount)
		{
			if ((CurTime - g_sBasket.OldDownHeartTime) > g_sBasket.DownHeartTime)
			{
				g_sBasket.OldDownHeartTime = CurTime;
				g_sHeart[g_nHeartDownCount].nLife = 1;
				g_sHeart[g_nHeartDownCount].nDist = 1;
				g_sHeart[g_nHeartDownCount].nX = g_sBasket.nX;
				g_sHeart[g_nHeartDownCount].nY = g_sBasket.nY + 1;
				g_sHeart[g_nHeartDownCount].OldMoveTime = CurTime;
				// 최소 100, 최대 399 밀리세컨드
				g_sHeart[g_nHeartDownCount].MoveTime = rand() % 300 + 100;
				g_nHeartDownCount++;
			}
		}
		else{
			g_sBasket.nDist = 0; // 하드 이동하지 못하게 한다.
		}

		nLength = g_sStageInfo.pStage[g_nStage].nBarLength;

		for (i = 0; i < g_nHeartDownCount; i++)
		{
			if (g_sHeart[i].nLife == 1)
			{
				if (CurTime - g_sHeart[i].OldMoveTime > g_sHeart[i].MoveTime)
				{
					g_sHeart[i].OldMoveTime = CurTime;
					g_sHeart[i].nY += g_sHeart[i].nDist;

					// Note: 막대기와 하트의 충돌 체크 
					if (g_sHeart[i].nY >= g_Bar.nY)
					{
						if ((g_sHeart[i].nX >= g_Bar.nX[0] && g_sHeart[i].nX <= (g_Bar.nX[nLength - 1] + 1))
							|| ((g_sHeart[i].nX + 1) >= g_Bar.nX[0] && (g_sHeart[i].nX + 1) <= (g_Bar.nX[nLength - 1] + 1)))
						{
							g_sHeart[i].nLife = 0;
							//득점과 연결
							g_nGrade += 10;
							g_nHeartCount++;
							g_nDeadHeartCount++;
						}
						else if (g_sHeart[i].nY > 22) // 하단의 경계 영역과 충돌
						{
							g_sHeart[i].nLife = 0;
							g_nDeadHeartCount++;
						}
					}
				}
			}
		}

		break;
	case STOP:
		//// 성공이냐 실패를 판단해주어서 출력을 해주는 부분이 와야 한다.  
		if (g_nHeartCount >= g_sStageInfo.pStage[g_nStage].nGoalHeartCount)
		{
			g_UpdateOldTime = CurTime;
			g_nGameState = SUCCESS;
			g_nTotalGrade += g_nGrade;
		}
		else{
			g_nGameState = FAILED;
		}
		break;
	case SUCCESS:
		if (CurTime - g_UpdateOldTime > 3000)
		{
			g_UpdateOldTime = CurTime;
			++g_nStage;
			hInit();
			g_nGameState = READY;
		}
		break;
	}
}

void AllMain::hRender()
{
	int i;
	char string[100];

	ScreenA.ScreenClear();

	switch (g_nGameState)
	{
	case INIT:
		if (g_nStage == 0)
			ScreenA.InitScreen();
		break;

	case READY:
		ScreenA.ReadyScreen();
		sprintf(string, "%d", g_nStage + 1);
		ScreenA.ScreenPrint(17, 11, string);
		break;
	case RUNNING:
		ScreenA.RunningScreen();

		sprintf(string, "스테이지 : %d", g_nStage + 1);
		ScreenA.ScreenPrint(47, 2, string);

		sprintf(string, "전체 하트 개수 : %d ", g_sStageInfo.pStage[g_nStage].nHeartCount);
		ScreenA.ScreenPrint(47, 4, string);

		sprintf(string, "목표 하트 개수 : %d ", g_sStageInfo.pStage[g_nStage].nGoalHeartCount);
		ScreenA.ScreenPrint(47, 6, string);

		sprintf(string, "담은 하트 개수 : %d ", g_nHeartCount);
		ScreenA.ScreenPrint(47, 8, string);

		sprintf(string, "점수 : %d ", g_nGrade);
		ScreenA.ScreenPrint(47, 10, string);

		ScreenA.ScreenPrint(g_sBasket.nX, g_sBasket.nY, "▦");

		for (i = 0; i < g_nHeartDownCount; i++)
		{
			if (g_sHeart[i].nLife == 1)
				ScreenA.ScreenPrint(g_sHeart[i].nX, g_sHeart[i].nY, "♡");
		}

		for (i = 0; i < g_Bar.nBarLength; i++)
			ScreenA.ScreenPrint(g_Bar.nX[i], g_Bar.nY, "▣");
		break;
	case SUCCESS:
		ScreenA.SuccessScreen();
		sprintf(string, "%d", g_nStage + 1);
		ScreenA.ScreenPrint(19, 7, string);
		sprintf(string, "총점: %d", g_nTotalGrade);
		ScreenA.ScreenPrint(18, 17, string);
		break;
	case FAILED:
		ScreenA.FailureScreen();
		sprintf(string, "%d", g_nStage + 1);
		ScreenA.ScreenPrint(20, 9, string);
		break;

	case RESULT:
		ScreenA.ResultScreen();
		sprintf(string, "%d", g_nTotalGrade);
		ScreenA.ScreenPrint(21, 11, string);
		break;
	}
	ScreenA.ScreenFlipping();
}

void AllMain::hRelease()
{
	free(g_sStageInfo.pStage);
}

void AllMain::dInit()
{
	int i;

	if (g_nStage == -1) // 1번만 초기화가 되는 부분에 대한 처리 사항
	{
		g_nStage = 0;
	}

	g_nDudagiCount = 0; // 잡은 두더지 개수	
	g_nGrade = 0;

	// Note: 망치 셋업
	g_Mangchi.nIsAttack = 0;
	g_Mangchi.nIndex = 0;
	g_Mangchi.nStayX = 38;
	g_Mangchi.nStayY = 10;
	g_Mangchi.StartTime = g_GameStartTime;
	g_Mangchi.DelayTime = 300;

	for (i = 0; i < 9; i++)
	{
		g_Dudagi[i].StayTime = rand() % g_StageInfo[g_nStage].DownLimitTime + 10; // Note: 최소 10은 된다.
		g_Dudagi[i].OldTime = clock();
		g_Dudagi[i].nState = DUDAGI_STATE::SETUP;
		g_Dudagi[i].OutPutTime = rand() % g_StageInfo[g_nStage].UpLimitTime + 10; //최소 10은 된다.
	}
}

void AllMain::dUpdate()
{
	int i;
	clock_t CurTime = clock();

	switch (g_nGameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 2000)  // 2초
		{
			g_nGameState = GAME_STATE::RUNNING;
			g_GameStartTime = CurTime;

		}
		break;
	case RUNNING:
		if ((CurTime - g_GameStartTime) > g_StageInfo[g_nStage].LimitTime)
		{
			g_nGameState = GAME_STATE::STOP;
			return;
		}
		else {
			// 두더지 업데이트	
			for (i = 0; i < 9; i++)
			{
				switch (g_Dudagi[i].nState)
				{
				case SETUP:
					g_Dudagi[i].OldTime = CurTime;
					g_Dudagi[i].OutPutTime = rand() % (int)g_StageInfo[g_nStage].UpLimitTime + 10;
					g_Dudagi[i].StayTime = rand() % (int)g_StageInfo[g_nStage].DownLimitTime + 10;
					g_Dudagi[i].nState = DUDAGI_STATE::UP;
					break;
				case UP:
					if (CurTime - g_Dudagi[i].OldTime > g_Dudagi[i].OutPutTime)
					{
						g_Dudagi[i].OldTime = CurTime;
						g_Dudagi[i].nState = DUDAGI_STATE::DOWN;
					}
					break;
				case DOWN:
					if (CurTime - g_Dudagi[i].OldTime > g_Dudagi[i].StayTime)
						g_Dudagi[i].nState = DUDAGI_STATE::SETUP;
					break;
				}
			}

			// 망치 업데이트 
			if (g_Mangchi.nIsAttack)
			{
				// 충돌 테스트 망치는 오직 하나의 두더지만 잡을 수 있기에 하나만 잡았으면 충돌 체크를 빠져 나온다.
				for (i = 0; i < 9; i++)
				{
					if (g_Dudagi[i].nState == UP && i == g_Mangchi.nIndex)
					{
						g_nGrade += 10;
						g_nDudagiCount++;
						g_Dudagi[i].nState = DUDAGI_STATE::DOWN; // 죽었으면 다운 상태로 바로 전환을 하도록 한다.															
						//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[4], 0, &g_Channel[4] );								
						break;
					}
				}

				// Note: 망치의 상태를 변경해주는 부분 망치로 쳤을 때에 일정한 시간 동안 머물도록 하기 위한 부분
				if (CurTime - g_Mangchi.StartTime > g_Mangchi.DelayTime)
				{
					g_Mangchi.nIsAttack = 0;
				}
			}

			g_RemainTime = (g_StageInfo[g_nStage].LimitTime - (CurTime - g_GameStartTime)) / 1000; // 게임 진행 남은 시간
		}
		break;
	case STOP:
		// 성공이냐 실패를 판단해주어서 출력을 해주는 부분이 와야 한다.
		if (g_nDudagiCount >= g_StageInfo[g_nStage].nCatchDudagi)
		{
			g_UpdateOldTime = CurTime;
			g_nGameState = GAME_STATE::SUCCESS;
			g_nTotalGrade += g_nGrade;
		}
		else {
			g_nGameState = GAME_STATE::FAILED;
		}
		break;
	case SUCCESS:
		if (CurTime - g_UpdateOldTime > 3000)
		{
			g_UpdateOldTime = CurTime;
			g_nGrade = 0;
			++g_nStage;
			dInit();
			g_nGameState = GAME_STATE::READY;
		}
		break;
	}
}

void AllMain::dRender()
{
	int i;
	char string[100];

	dscreen.ScreenClear();

	switch (g_nGameState)
	{
	case INIT:
		if (g_nStage == 0)
			dscreen.InitScreen();
		break;

	case READY:
		dscreen.ReadyScreen();
		sprintf(string, "%d", g_nStage + 1);
		dscreen.ScreenPrint(16, 11, string);
		break;

	case RUNNING:
		dscreen.RunningScreen();

		sprintf(string, "목표 두더지 : %d  잡은 두더지 : %d", g_StageInfo[g_nStage].nCatchDudagi, g_nDudagiCount);
		dscreen.ScreenPrint(2, 1, string);
		sprintf(string, "스테이지 : %d 점수 : %d 남은 시간 : %d ", g_nStage + 1, g_nGrade, g_RemainTime);
		dscreen.ScreenPrint(2, 2, string);

		for (i = 0; i < 9; i++)
		{
			if (g_Dudagi[i].nState == UP)
				dscreen.ScreenPrint(g_Point[i].nX, g_Point[i].nY, "●");

			dscreen.ScreenPrint(g_Point[i].nX, g_Point[i].nY + 1, "♨");
		}

		if (g_Mangchi.nIsAttack)
			g_Mangchi.MangchiW(g_Point[g_Mangchi.nIndex].nX, g_Point[g_Mangchi.nIndex].nY);
		else
			g_Mangchi.MangchiReady(g_Mangchi.nStayX, g_Mangchi.nStayY);
		break;

	case SUCCESS:
		dscreen.SuccessScreen();
		sprintf(string, "%d", g_nStage + 1);
		dscreen.ScreenPrint(20, 11, string);
		sprintf(string, "%d", g_nDudagiCount);
		dscreen.ScreenPrint(21, 17, string);
		sprintf(string, "%d", g_nTotalGrade);
		dscreen.ScreenPrint(14, 19, string);
		break;

	case FAILED:
		dscreen.FailureScreen();
		sprintf(string, "%d", g_nStage + 1);
		dscreen.ScreenPrint(16, 11, string);
		break;

	case RESULT:
		dscreen.ResultScreen();
		sprintf(string, "%d", g_nTotalGrade);
		dscreen.ScreenPrint(25, 11, string);
		break;
	}
	dscreen.ScreenFlipping();
}

void AllMain::hMain()
{
	int i, nKey;
	clock_t CurTime;

	ScreenA.ScreenInit();
	hInit();

	while (1)
	{
		CurTime = clock();
		if (_kbhit())
		{
			if (g_nGameState == RESULT)
				break;

			nKey = _getch();

			switch (nKey)
			{
			case ' ':
				if (g_nGameState == INIT && g_nStage == 0)
				{
					g_nGameState = READY;
					g_UpdateOldTime = clock();  // ready를 일정시간 지속해 주기 위해 							
				}
				break;
			case 'j':
				if (g_nGameState == RUNNING)
				{
					if (CurTime - g_Bar.OldMoveTime > g_Bar.MoveTime)
					{
						g_Bar.OldMoveTime = CurTime;
						if (g_Bar.nX[0] - 1 >= BOUNDARY_MIN)   // 경계 영역 처리 충돌 처리
						{
							for (i = 0; i < g_Bar.nBarLength; i++)
								g_Bar.nX[i] -= 1;
						}
					}
				}
				break;

			case 'l':
				if (g_nGameState == RUNNING)
				{
					if (CurTime - g_Bar.OldMoveTime > g_Bar.MoveTime)
					{
						g_Bar.OldMoveTime = CurTime;
						if (g_Bar.nX[g_Bar.nBarLength - 1] + 2 <= BOUNDARY_MAX) // 경계 영역 충돌 처리
						{
							for (i = 0; i < g_Bar.nBarLength; i++)
								g_Bar.nX[i] += 1;
						}
					}
				}
				break;
			case 'y':
			case 'Y':
				if (g_nGameState == FAILED)
				{
					hInit();
					g_nGameState = READY;
					g_UpdateOldTime = clock();
				}
				break;
			case 'n':
			case 'N':
				if (g_nGameState == FAILED)
				{
					g_nGameState = RESULT;
				}
				break;
			}
		}
		hUpdate();
		hRender();
	}

	hRelease();
	ScreenA.ScreenRelease();
}

void AllMain::dMain()
{
	int nKey;

	dInit();        // 초기화

	while (1)
	{
		if (_kbhit())
		{
			if (g_nGameState == RESULT)
				break;

			nKey = _getch();
			switch (nKey)
			{
			case ' ':
				if (g_nGameState == INIT && g_nStage == 0)
				{
					g_nGameState = GAME_STATE::READY;
					//FMOD_Channel_Stop( g_Channel[0] ); // 배경음 중지
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[2], 0, &g_Channel[2]); // READY 사운드 출력
					g_UpdateOldTime = clock();  // ready를 일정시간 지속해 주기 위해 							
				}
				break;
			case '1':  // 망치 키 입력 1 ~ 9까지
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (g_Mangchi.nIsAttack == 0 && g_nGameState == RUNNING)
				{
					g_Mangchi.nIndex = nKey - '1';
					g_Mangchi.StartTime = clock();
					g_Mangchi.nIsAttack = 1;
				}
				break;

			case 'y':
			case 'Y':
				if (g_nGameState == FAILED)
				{
					dInit();
					g_nGameState = GAME_STATE::READY;
					g_nGrade = 0;
					g_UpdateOldTime = clock();
				}
				break;
			case 'n':
			case 'N':
				if (g_nGameState == FAILED)
				{
					g_nGameState = GAME_STATE::RESULT;
				}
				break;
			}
		}

		dUpdate();    // 데이터 갱신
		dRender();    // 화면 출력
	}

	dscreen.ScreenRelease();
}