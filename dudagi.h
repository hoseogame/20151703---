#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

enum DUDAGI_STATE { SETUP, UP, DOWN };

class Dudagi
{
public:
	DUDAGI_STATE nState;	// Note: �δ��� ����	
	clock_t   StayTime;     // Note: ���� �� ��� �ð�
	clock_t	OutPutTime;     // Note: ������ �� ��� �ð�
	clock_t	OldTime;        // Note: ���� �ð�		
};