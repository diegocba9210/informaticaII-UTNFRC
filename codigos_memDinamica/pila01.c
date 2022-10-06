/*      Pila con memoria dinámica          */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct molde {
	int orden;
	char frase[80];
	struct molde *anterior;
} celda;

celda *base, *tope;
int ord = 0;

int entrada( void );
void salida( void );
void listar( void );

int main( void ) {
	char operac;

	base = (celda *) malloc( sizeof( celda ) );
	if( base == NULL ) {
		printf( "Problemas en asignación de memoria\n" );
		return 1;
	}
	base->anterior = NULL;
	tope = base ;

	do {
		printf( "\nOperación [Inser, Listar, Recup, Salir]: " );
		operac = getchar(); getchar();
		switch( toupper( operac ) ) {
			case 'I': entrada();
			break;
			case 'R': salida();
			break;
			case 'L': listar();
			break;
			case 'S': return 0;
			default: continue;
		}
	} while( 1 );
	return 0;
}

int entrada( void ) {
	celda *aux;
	aux = (celda *) malloc( sizeof( celda ) );
	if( aux == NULL ) {
		printf( "No hay más espacio para otro elemento\n" );
		return 1;
	}
	aux->anterior = tope;
	tope = aux;
	ord++;
	printf( "\nElemento Nro. %d: ", ord );
	scanf( "%s", tope->frase );
	getchar();
	tope->orden = ord;
	return 0;
}

void salida( void ) {
	if( tope == base ) {
		printf( "\nLa pila está vacía\n" );
		return;
	}
	printf( "\nRecuperado: %3d * %s\n", tope->orden, tope->frase );
	tope = tope->anterior;
	ord--;
}

void listar( void ) {
	celda *aux;
	if( tope == base ) return;
	puts( "\n" );
	aux = tope;
	do {
		printf( "Nro: %3d * %s\n", aux->orden, aux->frase );
		aux = aux->anterior;
	} while( aux != base );
}
