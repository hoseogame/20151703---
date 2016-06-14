#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "ScreenOut.h"

class Mangchi
{
public:
	int	nIsAttack;         // 망치 상태 
	clock_t	StartTime;     // 타격 상태가 시작된 시각
	clock_t	DelayTime;     // 타격 상태의 지연 시각
	int	nIndex;            // 좌표 배열에 접근하기 위한 인덱스
	int	nStayX, nStayY;    // 대기 상태일 때 좌표	
	void MangchiW( int x, int y );
	void MangchiReady( int x, int y );
};