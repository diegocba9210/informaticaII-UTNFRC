/*  Generación de una lista enlazada simple                    */
/*  Caso 2. Reserva de memoria elemento por elemento           */

#include <stdio.h>
#include <stdlib.h>
#define LUGARES 500

int main( void ) {
	typedef struct molde{
		int numero;
		long cuadrado;
		long cubo;
		struct molde *siguiente;
	} celda;

	celda *actual, *primero, *prox;
	int cont;

	actual = (celda *) malloc( sizeof( celda ) );
	if( !actual ) {
		printf( "Problemas en asignación de memoria\n" );
		exit(2);
	}
	primero = actual;

	for( cont=1; cont<=LUGARES; cont++ ) {
		actual->numero = cont;
		actual->cuadrado = (long) actual->numero * (long) actual->numero;
		actual->cubo = (long) actual->cuadrado * (long) actual->numero;

		if( cont < LUGARES ) {
			prox = (celda *) malloc( sizeof( celda ) );
			if( !prox ) {
				printf("Problemas en asignación de memoria\n");
				exit(2);
			}
			actual->siguiente = prox;
			actual = prox;
    		}
  	}

	actual->siguiente = NULL;
	actual = primero; 
	do {
		printf( "Número: %6d    Cuadrado: %8ld      Cubo: %10ld\n",
			 actual->numero, actual->cuadrado, actual->cubo );
		actual = actual->siguiente;
	} while (actual != NULL);

	return 0;
}
