#include "Mangchi.h"

dScreenOut mangchi3;

void Mangchi::MangchiW( int x, int y )
{
	mangchi3.ScreenPrint( x - 4, y - 1, "�٦�����" );
	mangchi3.ScreenPrint( x - 4, y, "�����Φ�������" );
	mangchi3.ScreenPrint( x - 4, y + 1, "�٦�����" );
}

void Mangchi::MangchiReady( int x, int y )
{
	mangchi3.ScreenPrint( x - 4, y - 2, "    ��" );
	mangchi3.ScreenPrint( x - 4, y - 1, "  ������" );
	mangchi3.ScreenPrint( x - 4, y, "  ��  ��" );
	mangchi3.ScreenPrint( x - 4, y + 1, "  ������" );
	mangchi3.ScreenPrint( x - 4, y + 2, "    ��" );
	mangchi3.ScreenPrint( x - 4, y + 3, "    ��" );
	mangchi3.ScreenPrint( x - 4, y + 4, "    ��" );
	mangchi3.ScreenPrint( x - 4, y + 5, "    ��" );
}