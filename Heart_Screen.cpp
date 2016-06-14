#include "Heart_Screen.h"

void ScreenAll::ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	// ������ �ܼ�â 2���� �����.
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// Ŀ�� �����
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

// 1 ~ 15 ���� ���� ���� ����
void ScreenAll::SetColor(unsigned short color)
{
	SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], color);
}

void ScreenAll::RunningScreen()
{
	ScreenPrint(0, 1, "����������������������������������������������");
	ScreenPrint(0, 2, "�����������������������릭");
	ScreenPrint(0, 3, "��                                          ��");
	ScreenPrint(0, 4, "��                                          ��");
	ScreenPrint(0, 5, "��                                          ��");
	ScreenPrint(0, 6, "��                                          ��");
	ScreenPrint(0, 7, "��                                          ��");
	ScreenPrint(0, 8, "��                                          ��");
	ScreenPrint(0, 9, "��                                          ��");
	ScreenPrint(0, 10, "��                                          ��");
	ScreenPrint(0, 11, "��                                          ��");
	ScreenPrint(0, 12, "��                                          ��");
	ScreenPrint(0, 13, "��                                          ��");
	ScreenPrint(0, 14, "��                                          ��");
	ScreenPrint(0, 15, "��                                          ��");
	ScreenPrint(0, 16, "��                                          ��");
	ScreenPrint(0, 17, "��                                          ��");
	ScreenPrint(0, 18, "��                                          ��");
	ScreenPrint(0, 19, "��                                          ��");
	ScreenPrint(0, 20, "��                                          ��");
	ScreenPrint(0, 21, "��                                          ��");
	ScreenPrint(0, 22, "��                                          ��");
	ScreenPrint(0, 23, "����������������������������������������������");
}
void ScreenAll::InitScreen()
{
	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "��                                          ��");
	ScreenPrint(0, 2, "��                                          ��");
	ScreenPrint(0, 3, "��                                          ��");
	ScreenPrint(0, 4, "��                   ��Ʈ ��� ����         ��");
	ScreenPrint(0, 5, "��                                          ��");
	ScreenPrint(0, 6, "��     ���ܦ�                               ��");
	ScreenPrint(0, 7, "��        ��                                ��");
	ScreenPrint(0, 8, "��          ��                              ��");
	ScreenPrint(0, 9, "��            ����                          ��");
	ScreenPrint(0, 10, "��              �� ��                       ��");
	ScreenPrint(0, 11, "��               ��                         ��");
	ScreenPrint(0, 12, "��          ��                              ��");
	ScreenPrint(0, 13, "��                         ��               ��");
	ScreenPrint(0, 14, "��      ����  ����        ��                ��");
	ScreenPrint(0, 15, "��       ��������������  ��    ��           ��");
	ScreenPrint(0, 16, "��        ������������   ��                 ��");
	ScreenPrint(0, 17, "��         ����������                       ��");
	ScreenPrint(0, 18, "��          ������    space �� ���� �ּ���  ��");
	ScreenPrint(0, 19, "��            ��                            ��");
	ScreenPrint(0, 20, "��          ���ۦ�                          ��");
	ScreenPrint(0, 21, "��                                          ��");
	ScreenPrint(0, 22, "��                                          ��");
	ScreenPrint(0, 23, "����������������������������������������������");

}
void ScreenAll::ReadyScreen()
{
	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "����������������������������������������������");
	ScreenPrint(0, 2, "����������������������������������������������");
	ScreenPrint(0, 3, "����������������������������������������������");
	ScreenPrint(0, 4, "����������������������������������������������");
	ScreenPrint(0, 5, "����������������������������������������������");
	ScreenPrint(0, 6, "����������������������������������������������");
	ScreenPrint(0, 7, "����������������������������������������������");
	ScreenPrint(0, 8, "����������������������������������������������");
	ScreenPrint(0, 9, "����������������������������������������������");
	ScreenPrint(0, 10, "������������                    ��������������");
	ScreenPrint(0, 11, "������������          ��������  ��������������");
	ScreenPrint(0, 12, "������������                    ��������������");
	ScreenPrint(0, 13, "����������������������������������������������");
	ScreenPrint(0, 14, "����������������������������������������������");
	ScreenPrint(0, 15, "����������������������������������������������");
	ScreenPrint(0, 16, "����������������������������������������������");
	ScreenPrint(0, 17, "����������������������������������������������");
	ScreenPrint(0, 18, "����������������������������������������������");
	ScreenPrint(0, 19, "����������������������������������������������");
	ScreenPrint(0, 20, "����������������������������������������������");
	ScreenPrint(0, 21, "����������������������������������������������");
	ScreenPrint(0, 22, "����������������������������������������������");
	ScreenPrint(0, 23, "����������������������������������������������");
}
void ScreenAll::SuccessScreen()
{
	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "����������������������������������������������");
	ScreenPrint(0, 2, "����������������������������������������������");
	ScreenPrint(0, 3, "����������������������������������������������");
	ScreenPrint(0, 4, "����������������������������������������������");
	ScreenPrint(0, 5, "����������������������������������������������");
	ScreenPrint(0, 6, "������������                    ��������������");
	ScreenPrint(0, 7, "������������          ��������  ��������������");
	ScreenPrint(0, 8, "������������                    ��������������");
	ScreenPrint(0, 9, "������������    �̼� ���� !!!   ��������������");
	ScreenPrint(0, 10, "������������                    ��������������");
	ScreenPrint(0, 11, "����������������������������������������������");
	ScreenPrint(0, 12, "����������������������������������������������");
	ScreenPrint(0, 13, "����������������������������������������������");
	ScreenPrint(0, 14, "����������������������������������������������");
	ScreenPrint(0, 15, "����������������������������������������������");
	ScreenPrint(0, 16, "����������������            ������������������");
	ScreenPrint(0, 17, "����������������            ������������������");
	ScreenPrint(0, 18, "����������������            ������������������");
	ScreenPrint(0, 19, "����������������������������������������������");
	ScreenPrint(0, 20, "����������������������������������������������");
	ScreenPrint(0, 21, "����������������������������������������������");
	ScreenPrint(0, 22, "����������������������������������������������");
	ScreenPrint(0, 23, "����������������������������������������������");
}
void ScreenAll::FailureScreen()
{
	ScreenPrint(0, 0, "����������������������������������������������");
	ScreenPrint(0, 1, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 2, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 3, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 4, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 5, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 6, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 7, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 8, "���͢͢͢͢�                      �ͦ͢͢͢͢�");
	ScreenPrint(0, 9, "���͢͢͢͢�           ��������   �ͦ͢͢͢͢�");
	ScreenPrint(0, 10, "���͢͢͢͢�                      �ͦ͢͢͢͢�");
	ScreenPrint(0, 11, "���͢͢͢͢�    �̼� ���� !!!!    �ͦ͢͢͢͢�");
	ScreenPrint(0, 12, "���͢͢͢͢�                      �ͦ͢͢͢͢�");
	ScreenPrint(0, 13, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 14, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 15, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 16, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 17, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 18, "���͢͢͢�                          �ͦ͢͢͢�");
	ScreenPrint(0, 19, "���͢͢͢� ��� �Ͻðڽ��ϱ�? (y/n) �ͦ͢͢͢�");
	ScreenPrint(0, 20, "���͢͢͢�                          �ͦ͢͢͢�");
	ScreenPrint(0, 21, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 22, "���ͦ͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢͢�");
	ScreenPrint(0, 23, "����������������������������������������������");
}
void ScreenAll::ResultScreen()
{
	ScreenPrint(0, 1, "����������������������������������������������");
	ScreenPrint(0, 2, "��                                          ��");
	ScreenPrint(0, 3, "��                                          ��");
	ScreenPrint(0, 4, "��         ((((    ��� ����    ))))        ��");
	ScreenPrint(0, 5, "��                                          ��");
	ScreenPrint(0, 6, "��               ���ܦ�                     ��");
	ScreenPrint(0, 7, "��                   ��                     ��");
	ScreenPrint(0, 8, "��                                          ��");
	ScreenPrint(0, 9, "��                                ��        ��");
	ScreenPrint(0, 10, "��                                          ��");
	ScreenPrint(0, 11, "��         ���� :             �� ��         ��");
	ScreenPrint(0, 12, "��                               ��         ��");
	ScreenPrint(0, 13, "��                               ��         ��");
	ScreenPrint(0, 14, "��                              ��          ��");
	ScreenPrint(0, 15, "��                 ����  ����        ��     ��");
	ScreenPrint(0, 16, "��               ��������������  ��    ��   ��");
	ScreenPrint(0, 17, "��                ������������   ��         ��");
	ScreenPrint(0, 18, "��                 ����������               ��");
	ScreenPrint(0, 19, "��                   ������                 ��");
	ScreenPrint(0, 20, "��                     ��                   ��");
	ScreenPrint(0, 21, "��                    ���ۦ�                ��");
	ScreenPrint(0, 22, "��                                          ��");
	ScreenPrint(0, 23, "����������������������������������������������");
}