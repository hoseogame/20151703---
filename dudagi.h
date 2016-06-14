#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

enum DUDAGI_STATE { SETUP, UP, DOWN };

class Dudagi
{
public:
	DUDAGI_STATE nState;	// Note: 두더지 상태	
	clock_t   StayTime;     // Note: 들어갔을 때 대기 시간
	clock_t	OutPutTime;     // Note: 나왔을 때 대기 시간
	clock_t	OldTime;        // Note: 이전 시각		
};