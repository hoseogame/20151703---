#include "ScreenOut.h"

void dScreenOut::InitScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                        ┃");
	ScreenPrint(0, 2, "┃                                        ┃");
	ScreenPrint(0, 3, "┃                                        ┃");
	ScreenPrint(0, 4, "┃                                        ┃");
	ScreenPrint(0, 5, "┃                                        ┃");
	ScreenPrint(0, 6, "┃                                        ┃");
	ScreenPrint(0, 7, "┃                                        ┃");
	ScreenPrint(0, 8, "┃             ////////                   ┃");
	ScreenPrint(0, 9, "┃             ┃＼ /┃ ＼│/             ┃");
	ScreenPrint(0, 10, "┃             ┃··┃┏┳┳┓           ┃");
	ScreenPrint(0, 11, "┃             ┗┓┏┛┗┓┏┛           ┃");
	ScreenPrint(0, 12, "┃                                        ┃");
	ScreenPrint(0, 13, "┃                                        ┃");
	ScreenPrint(0, 14, "┃                                        ┃");
	ScreenPrint(0, 15, "┃             두더지 잡기 게임           ┃");
	ScreenPrint(0, 16, "┃                                        ┃");
	ScreenPrint(0, 17, "┃          space 키를 눌러주세요         ┃");
	ScreenPrint(0, 18, "┃                                        ┃");
	ScreenPrint(0, 19, "┃                                        ┃");
	ScreenPrint(0, 20, "┃                                        ┃");
	ScreenPrint(0, 21, "┃                                        ┃");
	ScreenPrint(0, 22, "┃                                        ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");

}

void dScreenOut::ReadyScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 2, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 3, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 4, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 5, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 6, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 7, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 8, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 9, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 10, "┃■■■■■                    ■■■■■┃");
	ScreenPrint(0, 11, "┃■■■■■        스테이지    ■■■■■┃");
	ScreenPrint(0, 12, "┃■■■■■                    ■■■■■┃");
	ScreenPrint(0, 13, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 14, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 15, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 16, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 17, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 18, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 19, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 20, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 21, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 22, "┃■■■■■■■■■■■■■■■■■■■■┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");

}

void dScreenOut::SuccessScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                        ┃");
	ScreenPrint(0, 2, "┃                                        ┃");
	ScreenPrint(0, 3, "┃                                        ┃");
	ScreenPrint(0, 4, "┃             // / // ＼＼＼             ┃");
	ScreenPrint(0, 5, "┃             │/＼    /＼│♬           ┃");
	ScreenPrint(0, 6, "┃             │≡  ▽  ≡│○           ┃");
	ScreenPrint(0, 7, "┃              ＼_________///            ┃");
	ScreenPrint(0, 8, "┃                                        ┃");
	ScreenPrint(0, 9, "┃                                        ┃");
	ScreenPrint(0, 10, "┃                                        ┃");
	ScreenPrint(0, 11, "┃                       스테이지         ┃");
	ScreenPrint(0, 12, "┃                                        ┃");
	ScreenPrint(0, 13, "┃                   미션 성공 !!!!       ┃");
	ScreenPrint(0, 14, "┃                                        ┃");
	ScreenPrint(0, 15, "┃                                        ┃");
	ScreenPrint(0, 16, "┃                                        ┃");
	ScreenPrint(0, 17, "┃     잡은 두더지 :                      ┃");
	ScreenPrint(0, 18, "┃                                        ┃");
	ScreenPrint(0, 19, "┃     총점 :                             ┃");
	ScreenPrint(0, 20, "┃                                        ┃");
	ScreenPrint(0, 21, "┃                                        ┃");
	ScreenPrint(0, 22, "┃                                        ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");

}

void dScreenOut::RunningScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                        ┃");
	ScreenPrint(0, 2, "┃                                        ┃");
	ScreenPrint(0, 3, "┃                                        ┃");
	ScreenPrint(0, 4, "┃                                        ┃");
	ScreenPrint(0, 5, "┃                                        ┃");
	ScreenPrint(0, 6, "┃                                        ┃");
	ScreenPrint(0, 7, "┃                                        ┃");
	ScreenPrint(0, 8, "┃                                        ┃");
	ScreenPrint(0, 9, "┃                                        ┃");
	ScreenPrint(0, 10, "┃                                        ┃");
	ScreenPrint(0, 11, "┃                                        ┃");
	ScreenPrint(0, 12, "┃                                        ┃");
	ScreenPrint(0, 13, "┃                                        ┃");
	ScreenPrint(0, 14, "┃                                        ┃");
	ScreenPrint(0, 15, "┃                                        ┃");
	ScreenPrint(0, 16, "┃                                        ┃");
	ScreenPrint(0, 17, "┃                                        ┃");
	ScreenPrint(0, 18, "┃                                        ┃");
	ScreenPrint(0, 19, "┃                            ○    ●    ┃");
	ScreenPrint(0, 20, "┃                          ┏■┛┏□┛  ┃");
	ScreenPrint(0, 21, "┃                            ┛┓  ┛┓  ┃");
	ScreenPrint(0, 22, "┃                                        ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");

}

void dScreenOut::FailureScreen()
{
	ScreenPrint(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓");
	ScreenPrint(0, 1, "┃                                        ┃");
	ScreenPrint(0, 2, "┃                                        ┃");
	ScreenPrint(0, 3, "┃                                        ┃");
	ScreenPrint(0, 4, "┃                                        ┃");
	ScreenPrint(0, 5, "┃                                        ┃");
	ScreenPrint(0, 6, "┃             ┎-━━-┒                 ┃");
	ScreenPrint(0, 7, "┃             d ご,.ご b                 ┃");
	ScreenPrint(0, 8, "┃             ┃┭─┮┃                 ┃");
	ScreenPrint(0, 9, "┃             ┖┦│┞┚                 ┃");
	ScreenPrint(0, 10, "┃               ┕┷┙                   ┃");
	ScreenPrint(0, 11, "┃                    스테이지            ┃");
	ScreenPrint(0, 12, "┃                                        ┃");
	ScreenPrint(0, 13, "┃            미션 실패 !!!!              ┃");
	ScreenPrint(0, 14, "┃                                        ┃");
	ScreenPrint(0, 15, "┃                                        ┃");
	ScreenPrint(0, 16, "┃                                        ┃");
	ScreenPrint(0, 17, "┃      다시 하시겠습니까? ( y/n )        ┃");
	ScreenPrint(0, 18, "┃                                        ┃");
	ScreenPrint(0, 19, "┃                                        ┃");
	ScreenPrint(0, 20, "┃                                        ┃");
	ScreenPrint(0, 21, "┃                                        ┃");
	ScreenPrint(0, 22, "┃                                        ┃");
	ScreenPrint(0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛");

}

void dScreenOut::ResultScreen()
{
	ScreenPrint( 0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓" );
	ScreenPrint( 0, 1, "┃                                        ┃" );
	ScreenPrint( 0, 2, "┃                                        ┃" );
	ScreenPrint( 0, 3, "┃                                        ┃" );
	ScreenPrint( 0, 4, "┃                                        ┃" );
	ScreenPrint( 0, 5, "┃                                        ┃" );
	ScreenPrint( 0, 6, "┃                                        ┃" );
	ScreenPrint( 0, 7, "┃  (((    두더지 잡기 게임 Score  ))))   ┃" );
	ScreenPrint( 0, 8, "┃                                        ┃" );
	ScreenPrint( 0, 9, "┃                                        ┃" );
	ScreenPrint( 0, 10, "┃                                        ┃" );
	ScreenPrint( 0, 11, "┃           총 점수  :                   ┃" );
	ScreenPrint( 0, 12, "┃                                        ┃" );
	ScreenPrint( 0, 13, "┃                                        ┃" );
	ScreenPrint( 0, 14, "┃                                        ┃" );
	ScreenPrint( 0, 15, "┃                                        ┃" );
	ScreenPrint( 0, 16, "┃                                        ┃" );
	ScreenPrint( 0, 17, "┃                                        ┃" );
	ScreenPrint( 0, 18, "┃                                        ┃" );
	ScreenPrint( 0, 19, "┃                                        ┃" );
	ScreenPrint( 0, 20, "┃                                        ┃" );
	ScreenPrint( 0, 21, "┃                                        ┃" );
	ScreenPrint( 0, 22, "┃                                        ┃" );
	ScreenPrint( 0, 23, "┗━━━━━━━━━━━━━━━━━━━━┛" );

}

void dScreenOut::ScreenInit()
{
	CONSOLE_CURSOR_INFO cci;

	// 가상의 콘솔창 2개룰 만든다.
	dg_hScreen[0] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL );
	dg_hScreen[1] = CreateConsoleScreenBuffer( GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL );

	// 커서 숨기기
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo( dg_hScreen[0], &cci );
	SetConsoleCursorInfo( dg_hScreen[1], &cci );
}

void dScreenOut::ScreenFlipping()
{
	Sleep( 10 );
	SetConsoleActiveScreenBuffer( dg_hScreen[dg_nScreenIndex] );
	dg_nScreenIndex = !dg_nScreenIndex;
}

void dScreenOut::ScreenClear()
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter( dg_hScreen[dg_nScreenIndex], ' ', 80 * 25, Coor, &dw );
}

void dScreenOut::ScreenRelease()
{
	CloseHandle( dg_hScreen[0] );
	CloseHandle( dg_hScreen[1] );
}

void dScreenOut::ScreenPrint(int x, int y, char *string)
{
	gotoxy(x, y);
	printf("%s", string);
}

void dScreenOut::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// 1 ~ 15 까지 색상 설정 가능
void dScreenOut::SetColor( unsigned short color )
{
	SetConsoleTextAttribute( dg_hScreen[dg_nScreenIndex], color );
}