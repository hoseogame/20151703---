#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "ScreenOut.h"

class Mangchi
{
public:
	int	nIsAttack;         // ��ġ ���� 
	clock_t	StartTime;     // Ÿ�� ���°� ���۵� �ð�
	clock_t	DelayTime;     // Ÿ�� ������ ���� �ð�
	int	nIndex;            // ��ǥ �迭�� �����ϱ� ���� �ε���
	int	nStayX, nStayY;    // ��� ������ �� ��ǥ	
	void MangchiW( int x, int y );
	void MangchiReady( int x, int y );
};