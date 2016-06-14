#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

static int dg_nScreenIndex = 0;
static HANDLE dg_hScreen[2];

class dScreenOut
{
public:
	void InitScreen();
	void ReadyScreen();
	void SuccessScreen();
	void RunningScreen();
	void FailureScreen();
	void ResultScreen();

	void gotoxy(int x, int y);
	void ScreenInit();
	void ScreenFlipping();
	void ScreenClear();
	void ScreenRelease();
	void ScreenPrint( int x, int y, char *string );
	void SetColor( unsigned short color );
};