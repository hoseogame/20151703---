#include "Heart_Header.h"

int main()
{ 
	AllMain Allmain;
	
	return 0;
}

AllMain::AllMain()
{
	int k = 0;
	printf("������ �������ּ���. 1=�δ���. 2=��Ʈ");
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
	int nBarLength;	// Note: ����� ����
	int nX[7], nY;	// Note: ��ǥ     
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
	int nLife;	           // ����
	int nX, nY;	 // ��ǥ
	int nDist;            // �̵��Ÿ�
	clock_t MoveTime;   // �̵� �ð� ���� 
	clock_t OldMoveTime;     // ���� �̵� �ð�
} HEART;

BAR g_Bar;
BASKET g_sBasket;
HEART  g_sHeart[100];

void AllMain::hInit()
{
	int i;
	FILE *fp;

	if (g_nStage == -1) // 1���� �ʱ�ȭ�� �Ǵ� �κп� ���� ó�� ����
	{
		g_nStage = 0;

		//�������� ����
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

	// Note: ����� �ʱ�ȭ      	 
	g_Bar.nY = 22;
	g_Bar.nBarLength = g_sStageInfo.pStage[g_nStage].nBarLength; // ������� ���� 
	g_Bar.OldMoveTime = clock();
	g_Bar.MoveTime = 40;

	for (i = 0; i < g_Bar.nBarLength; i++)
	{
		g_Bar.nX[i] = 10 + 2 * (i + 1); // 15 �÷�����		
	}

	// Note: ��Ʈ �ٱ��� �ʱ�ȭ
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
		if (CurTime - g_UpdateOldTime > 3000)  // 2��
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
				// �ּ� 100, �ִ� 399 �и�������
				g_sHeart[g_nHeartDownCount].MoveTime = rand() % 300 + 100;
				g_nHeartDownCount++;
			}
		}
		else{
			g_sBasket.nDist = 0; // �ϵ� �̵����� ���ϰ� �Ѵ�.
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

					// Note: ������ ��Ʈ�� �浹 üũ 
					if (g_sHeart[i].nY >= g_Bar.nY)
					{
						if ((g_sHeart[i].nX >= g_Bar.nX[0] && g_sHeart[i].nX <= (g_Bar.nX[nLength - 1] + 1))
							|| ((g_sHeart[i].nX + 1) >= g_Bar.nX[0] && (g_sHeart[i].nX + 1) <= (g_Bar.nX[nLength - 1] + 1)))
						{
							g_sHeart[i].nLife = 0;
							//������ ����
							g_nGrade += 10;
							g_nHeartCount++;
							g_nDeadHeartCount++;
						}
						else if (g_sHeart[i].nY > 22) // �ϴ��� ��� ������ �浹
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
		//// �����̳� ���и� �Ǵ����־ ����� ���ִ� �κ��� �;� �Ѵ�.  
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

		sprintf(string, "�������� : %d", g_nStage + 1);
		ScreenA.ScreenPrint(47, 2, string);

		sprintf(string, "��ü ��Ʈ ���� : %d ", g_sStageInfo.pStage[g_nStage].nHeartCount);
		ScreenA.ScreenPrint(47, 4, string);

		sprintf(string, "��ǥ ��Ʈ ���� : %d ", g_sStageInfo.pStage[g_nStage].nGoalHeartCount);
		ScreenA.ScreenPrint(47, 6, string);

		sprintf(string, "���� ��Ʈ ���� : %d ", g_nHeartCount);
		ScreenA.ScreenPrint(47, 8, string);

		sprintf(string, "���� : %d ", g_nGrade);
		ScreenA.ScreenPrint(47, 10, string);

		ScreenA.ScreenPrint(g_sBasket.nX, g_sBasket.nY, "��");

		for (i = 0; i < g_nHeartDownCount; i++)
		{
			if (g_sHeart[i].nLife == 1)
				ScreenA.ScreenPrint(g_sHeart[i].nX, g_sHeart[i].nY, "��");
		}

		for (i = 0; i < g_Bar.nBarLength; i++)
			ScreenA.ScreenPrint(g_Bar.nX[i], g_Bar.nY, "��");
		break;
	case SUCCESS:
		ScreenA.SuccessScreen();
		sprintf(string, "%d", g_nStage + 1);
		ScreenA.ScreenPrint(19, 7, string);
		sprintf(string, "����: %d", g_nTotalGrade);
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

	if (g_nStage == -1) // 1���� �ʱ�ȭ�� �Ǵ� �κп� ���� ó�� ����
	{
		g_nStage = 0;
	}

	g_nDudagiCount = 0; // ���� �δ��� ����	
	g_nGrade = 0;

	// Note: ��ġ �¾�
	g_Mangchi.nIsAttack = 0;
	g_Mangchi.nIndex = 0;
	g_Mangchi.nStayX = 38;
	g_Mangchi.nStayY = 10;
	g_Mangchi.StartTime = g_GameStartTime;
	g_Mangchi.DelayTime = 300;

	for (i = 0; i < 9; i++)
	{
		g_Dudagi[i].StayTime = rand() % g_StageInfo[g_nStage].DownLimitTime + 10; // Note: �ּ� 10�� �ȴ�.
		g_Dudagi[i].OldTime = clock();
		g_Dudagi[i].nState = DUDAGI_STATE::SETUP;
		g_Dudagi[i].OutPutTime = rand() % g_StageInfo[g_nStage].UpLimitTime + 10; //�ּ� 10�� �ȴ�.
	}
}

void AllMain::dUpdate()
{
	int i;
	clock_t CurTime = clock();

	switch (g_nGameState)
	{
	case READY:
		if (CurTime - g_UpdateOldTime > 2000)  // 2��
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
			// �δ��� ������Ʈ	
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

			// ��ġ ������Ʈ 
			if (g_Mangchi.nIsAttack)
			{
				// �浹 �׽�Ʈ ��ġ�� ���� �ϳ��� �δ����� ���� �� �ֱ⿡ �ϳ��� ������� �浹 üũ�� ���� ���´�.
				for (i = 0; i < 9; i++)
				{
					if (g_Dudagi[i].nState == UP && i == g_Mangchi.nIndex)
					{
						g_nGrade += 10;
						g_nDudagiCount++;
						g_Dudagi[i].nState = DUDAGI_STATE::DOWN; // �׾����� �ٿ� ���·� �ٷ� ��ȯ�� �ϵ��� �Ѵ�.															
						//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[4], 0, &g_Channel[4] );								
						break;
					}
				}

				// Note: ��ġ�� ���¸� �������ִ� �κ� ��ġ�� ���� ���� ������ �ð� ���� �ӹ����� �ϱ� ���� �κ�
				if (CurTime - g_Mangchi.StartTime > g_Mangchi.DelayTime)
				{
					g_Mangchi.nIsAttack = 0;
				}
			}

			g_RemainTime = (g_StageInfo[g_nStage].LimitTime - (CurTime - g_GameStartTime)) / 1000; // ���� ���� ���� �ð�
		}
		break;
	case STOP:
		// �����̳� ���и� �Ǵ����־ ����� ���ִ� �κ��� �;� �Ѵ�.
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

		sprintf(string, "��ǥ �δ��� : %d  ���� �δ��� : %d", g_StageInfo[g_nStage].nCatchDudagi, g_nDudagiCount);
		dscreen.ScreenPrint(2, 1, string);
		sprintf(string, "�������� : %d ���� : %d ���� �ð� : %d ", g_nStage + 1, g_nGrade, g_RemainTime);
		dscreen.ScreenPrint(2, 2, string);

		for (i = 0; i < 9; i++)
		{
			if (g_Dudagi[i].nState == UP)
				dscreen.ScreenPrint(g_Point[i].nX, g_Point[i].nY, "��");

			dscreen.ScreenPrint(g_Point[i].nX, g_Point[i].nY + 1, "��");
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
					g_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
				}
				break;
			case 'j':
				if (g_nGameState == RUNNING)
				{
					if (CurTime - g_Bar.OldMoveTime > g_Bar.MoveTime)
					{
						g_Bar.OldMoveTime = CurTime;
						if (g_Bar.nX[0] - 1 >= BOUNDARY_MIN)   // ��� ���� ó�� �浹 ó��
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
						if (g_Bar.nX[g_Bar.nBarLength - 1] + 2 <= BOUNDARY_MAX) // ��� ���� �浹 ó��
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

	dInit();        // �ʱ�ȭ

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
					//FMOD_Channel_Stop( g_Channel[0] ); // ����� ����
					//FMOD_System_PlaySound( g_System, FMOD_CHANNEL_FREE, g_Sound[2], 0, &g_Channel[2]); // READY ���� ���
					g_UpdateOldTime = clock();  // ready�� �����ð� ������ �ֱ� ���� 							
				}
				break;
			case '1':  // ��ġ Ű �Է� 1 ~ 9����
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

		dUpdate();    // ������ ����
		dRender();    // ȭ�� ���
	}

	dscreen.ScreenRelease();
}