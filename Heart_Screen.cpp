#include "Heart_Screen.h"

void ScreenAll::ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	// 가상의 콘솔창 2개룰 만든다.
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서 숨기기
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);
}

void ScreenAll::ScreenFlipping()
{
	Sleep(10);
	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void ScreenAll::ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 25, Coor, &dw);
}

void ScreenAll::ScreenRelease()
{
	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);
}


void ScreenAll::ScreenPrint(int x, int y, char *string)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
}

// 1 ~ 15 까지 색상 설정 가능
void ScreenAll::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

void ScreenAll::RunningScreen()
{
	ScreenPrint(0, 1, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 2, "┃〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	ScreenPrint(0, 4, "┃                                          ┃");
	ScreenPrint(0, 5, "┃                                          ┃");
	ScreenPrint(0, 6, "┃                                          ┃");
	ScreenPrint(0, 7, "┃                                          ┃");
	ScreenPrint(0, 8, "┃                                          ┃");
	ScreenPrint(0, 9, "┃                                          ┃");
	ScreenPrint(0, 10, "┃                                          ┃");
	ScreenPrint(0, 11, "┃                                          ┃");
	ScreenPrint(0, 12, "┃                                          ┃");
	ScreenPrint(0, 13, "┃                                          ┃");
	ScreenPrint(0, 14, "┃                                          ┃");
	ScreenPrint(0, 15, "┃                                          ┃");
	ScreenPrint(0, 16, "┃                                          ┃");
	ScreenPrint(0, 17, "┃                                          ┃");
	ScreenPrint(0, 18, "┃                                          ┃");
	ScreenPrint(0, 19, "┃                                          ┃");
	ScreenPrint(0, 20, "┃                                          ┃");
	ScreenPrint(0, 21, "┃                                          ┃");
	ScreenPrint(0, 22, "┃                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void ScreenAll::InitScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                          ┃");
	ScreenPrint(0, 2, "┃                                          ┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	ScreenPrint(0, 4, "┃                   하트 담기 게임         ┃");
	ScreenPrint(0, 5, "┃                                          ┃");
	ScreenPrint(0, 6, "┃     ┏●┓                               ┃");
	ScreenPrint(0, 7, "┃        ♡                                ┃");
	ScreenPrint(0, 8, "┃          ♡                              ┃");
	ScreenPrint(0, 9, "┃            ♡♡                          ┃");
	ScreenPrint(0, 10, "┃              ♡ ♡                       ┃");
	ScreenPrint(0, 11, "┃               ♡                         ┃");
	ScreenPrint(0, 12, "┃          ♡                              ┃");
	ScreenPrint(0, 13, "┃                         ♡               ┃");
	ScreenPrint(0, 14, "┃      ♡♡  ♡♡        ♡                ┃");
	ScreenPrint(0, 15, "┃       ♡♡♡♡♡♡♡  ♡    ♡           ┃");
	ScreenPrint(0, 16, "┃        ♡♡♡♡♡♡   ♡                 ┃");
	ScreenPrint(0, 17, "┃         ♡♡♡♡♡                       ┃");
	ScreenPrint(0, 18, "┃          ♡♡♡    space 를 눌러 주세요  ┃");
	ScreenPrint(0, 19, "┃            ♡                            ┃");
	ScreenPrint(0, 20, "┃          ┗○┛                          ┃");
	ScreenPrint(0, 21, "┃                                          ┃");
	ScreenPrint(0, 22, "┃                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");

}
void ScreenAll::ReadyScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 2, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 3, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 4, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 5, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 6, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 7, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 8, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 9, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 10, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	ScreenPrint(0, 11, "┃♡♡♡♡♡          스테이지  ♡♡♡♡♡♡┃");
	ScreenPrint(0, 12, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	ScreenPrint(0, 13, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 14, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 15, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 16, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 17, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 18, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 19, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 20, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 21, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 22, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void ScreenAll::SuccessScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 2, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 3, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 4, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 5, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 6, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	ScreenPrint(0, 7, "┃♡♡♡♡♡          스테이지  ♡♡♡♡♡♡┃");
	ScreenPrint(0, 8, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	ScreenPrint(0, 9, "┃♡♡♡♡♡    미션 성공 !!!   ♡♡♡♡♡♡┃");
	ScreenPrint(0, 10, "┃♡♡♡♡♡                    ♡♡♡♡♡♡┃");
	ScreenPrint(0, 11, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 12, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 13, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 14, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 15, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 16, "┃♡♡♡♡♡♡♡            ♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 17, "┃♡♡♡♡♡♡♡            ♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 18, "┃♡♡♡♡♡♡♡            ♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 19, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 20, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 21, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 22, "┃♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡♡┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void ScreenAll::FailureScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 2, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 3, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 4, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 5, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 6, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 7, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 8, "┃♨♨♨♨♨                      ♨♨♨♨♨┃");
	ScreenPrint(0, 9, "┃♨♨♨♨♨           스테이지   ♨♨♨♨♨┃");
	ScreenPrint(0, 10, "┃♨♨♨♨♨                      ♨♨♨♨♨┃");
	ScreenPrint(0, 11, "┃♨♨♨♨♨    미션 실패 !!!!    ♨♨♨♨♨┃");
	ScreenPrint(0, 12, "┃♨♨♨♨♨                      ♨♨♨♨♨┃");
	ScreenPrint(0, 13, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 14, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 15, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 16, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 17, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 18, "┃♨♨♨♨                          ♨♨♨♨┃");
	ScreenPrint(0, 19, "┃♨♨♨♨ 계속 하시겠습니까? (y/n) ♨♨♨♨┃");
	ScreenPrint(0, 20, "┃♨♨♨♨                          ♨♨♨♨┃");
	ScreenPrint(0, 21, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 22, "┃♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨♨┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}
void ScreenAll::ResultScreen()
{
	ScreenPrint(0, 1, "┏━━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 2, "┃                                          ┃");
	ScreenPrint(0, 3, "┃                                          ┃");
	ScreenPrint(0, 4, "┃         ((((    결과 보기    ))))        ┃");
	ScreenPrint(0, 5, "┃                                          ┃");
	ScreenPrint(0, 6, "┃               ┏●┓                     ┃");
	ScreenPrint(0, 7, "┃                   ♡                     ┃");
	ScreenPrint(0, 8, "┃                                          ┃");
	ScreenPrint(0, 9, "┃                                ♡        ┃");
	ScreenPrint(0, 10, "┃                                          ┃");
	ScreenPrint(0, 11, "┃         총점 :             ♡ ♡         ┃");
	ScreenPrint(0, 12, "┃                               ♡         ┃");
	ScreenPrint(0, 13, "┃                               ♡         ┃");
	ScreenPrint(0, 14, "┃                              ♡          ┃");
	ScreenPrint(0, 15, "┃                 ♡♡  ♡♡        ♡     ┃");
	ScreenPrint(0, 16, "┃               ♡♡♡♡♡♡♡  ♡    ♡   ┃");
	ScreenPrint(0, 17, "┃                ♡♡♡♡♡♡   ♡         ┃");
	ScreenPrint(0, 18, "┃                 ♡♡♡♡♡               ┃");
	ScreenPrint(0, 19, "┃                   ♡♡♡                 ┃");
	ScreenPrint(0, 20, "┃                     ♡                   ┃");
	ScreenPrint(0, 21, "┃                    ┗○┛                ┃");
	ScreenPrint(0, 22, "┃                                          ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━━┛");
}