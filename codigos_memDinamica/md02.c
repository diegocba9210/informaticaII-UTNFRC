/* Programa que reserva, ocupa y libera memoria dinámica */

#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char * const argv[] ) {
	int *p, *q;
	
	p = (int *) malloc( sizeof(int) );
	*p = 5;
	q = (int *) malloc( sizeof(int) );
	*q = 8;
	printf( "%d %d\n", *p, *q );

	free( p );
	printf( "%d %d\n", *p, *q );

	p = q;
	q = (int *) malloc( sizeof(int) );
	*q = 6;
	printf( "%d %d\n", *p, *q );

	free( p );
	free( q );
	printf( "%d %d\n", *p, *q );

	return 0;
}
