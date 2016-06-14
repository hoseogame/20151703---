#pragma once
#include <windows.h>

static int g_nScreenIndex;
static HANDLE g_hScreen[2];

class ScreenAll {
private:
	void SetColor(unsigned short color);
public:
	void ScreenInit();
	void ScreenFlipping();
	void ScreenClear();
	void ScreenRelease();
	void ScreenPrint(int x, int y, char *string);

	void ResultScreen();
	void FailureScreen();
	void SuccessScreen();
	void ReadyScreen();
	void InitScreen();
	void RunningScreen();
};