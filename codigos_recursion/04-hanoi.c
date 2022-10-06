#include <stdio.h>

void movertorre( int alt, int or, int de, int in );
void moverdisco( int ori, int des );

main() {
	int h, orig = 1, dest = 3, interm = 2;

	printf( "Altura de la Torre: " );
	scanf( "%d", &h );
	printf( "Movimiento de una torre de altura " );
	printf( "%2d, de %1d a %1d pasando por %1d\n\n", h, orig, dest, interm );
	movertorre( h, orig, dest, interm );
	printf( "\n" );
}

void movertorre( int alt, int or, int de, int in ) {
	if( alt > 0 ) {
		movertorre( alt - 1, or, in, de );
		moverdisco( or, de );
		movertorre( alt - 1, in, de, or );
  	}
}

void moverdisco( int ori, int des ) {
	static long movimiento = 1;

	printf( "Mov. %6ld   de: %1d  a: %1d\n", movimiento++, ori, des );
}
