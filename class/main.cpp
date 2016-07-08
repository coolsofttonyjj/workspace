/**
 * @file main.cpp
 * @brief	
 * @author 
 * @version 1.1
 * @date 2016-04-12
 */

#include <stdio.h>
#include "player.h"
#include "npc.h"

int main( int argc, char* argv[] )
{
	printf( "Hello World\n" );
	printf("Hehe\n");
	Player _p;
	_p.Init();
	Npc _n;
	printf( "%d", _n.a );
	return 0;
}
