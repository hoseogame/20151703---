#include "Mangchi.h"

dScreenOut mangchi3;

void Mangchi::MangchiW( int x, int y )
{
	mangchi3.ScreenPrint( x - 4, y - 1, "≧旨收旬" );
	mangchi3.ScreenPrint( x - 4, y, "↖早統早㏑㏑↖↗" );
	mangchi3.ScreenPrint( x - 4, y + 1, "≧曲收旭" );
}

void Mangchi::MangchiReady( int x, int y )
{
	mangchi3.ScreenPrint( x - 4, y - 2, "    ↘" );
	mangchi3.ScreenPrint( x - 4, y - 1, "  旨收旬" );
	mangchi3.ScreenPrint( x - 4, y, "  早  早" );
	mangchi3.ScreenPrint( x - 4, y + 1, "  曲收旭" );
	mangchi3.ScreenPrint( x - 4, y + 2, "    ‵" );
	mangchi3.ScreenPrint( x - 4, y + 3, "    ‵" );
	mangchi3.ScreenPrint( x - 4, y + 4, "    ↘" );
	mangchi3.ScreenPrint( x - 4, y + 5, "    ↙" );
}