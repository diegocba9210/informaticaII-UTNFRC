/*  Generación de una lista enlazada simple                     */
/*  Caso 1. Reserva de toda la memoria al principio             */

#include <stdio.h>
#include <stdlib.h>
#define LUGARES 500

int main( void ) {
	struct molde {
		int numero;
		long cuadrado;
		long cubo;
		struct molde *siguiente;
	};

	  struct molde *actual, *primero;
	  int cont;

	actual = (struct molde *) malloc(sizeof( struct molde) * LUGARES );
	if( !actual ) {
		printf( "Problemas en asignación de memoria\n" );
	exit(2);
	}
  
	primero = actual;
	for( cont=1; cont<=LUGARES; cont++ ) {
		actual->numero = cont;
		actual->cuadrado = (long) actual->numero * (long) actual->numero;
		actual->cubo = (long) actual->cuadrado * (long) actual->numero;
		actual->siguiente = actual+1;
		actual++;
	}
	actual--;
	actual->siguiente = NULL;

	actual = primero;
	do {
		printf( "Número: %6d    Cuadrado: %8ld      Cubo: %10ld\n",
	        	 actual->numero, actual->cuadrado, actual->cubo );
		actual = actual->siguiente;
	} while (actual != NULL);
 
	return 0;
}
