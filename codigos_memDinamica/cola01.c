/*    Cola simple utilizando memoria dinámica   */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct molde {
	int orden;
	char frase[80];
	struct molde *siguiente;
} celda;

celda *pri, *sig;

int insertar( void );
void recuperar( void );
void listar( void );

int main( void ) {
	char operac;

	sig = (celda *) malloc( sizeof( celda ) );
	if( sig == NULL ) {
		printf( "Problemas en asignación de memoria\n" );
		return 1;
	}
  
	sig->siguiente = NULL;
	pri = sig ;
  
	do {
		printf( "\nOperación [Inser, Listar, Recup, Salir]: " );
		operac = getchar(); getchar();
		switch( toupper( operac ) ) {
			case 'I': insertar();
			break;
			case 'R': recuperar();
			break;
			case 'L': listar();
			break;
			case 'S': return 0;
			default: continue;
		}
	} while( operac != 'S' );
	return 0;
}

int insertar( void ) {
	static int ord = 1;

	celda *aux;
	printf( "\nElemento Nro. %d: ", ord );
	scanf( "%s", sig->frase );
	getchar();
	sig->orden = ord;
	aux = (celda *) malloc( sizeof( celda ) );
	if( aux == NULL ) {
		printf( "No hay más espacio para otro elemento\n" );
		return 1;
	}
	sig->siguiente = aux;
	aux->siguiente = NULL;
	sig = aux;
	ord++;
	return 0;
}

void recuperar( void ) {
	if( pri == sig ) {
		printf( "\nLa cola está vacía\n" );
		return;
	}
	printf( "\nRecuperado: %3d * %s\n", pri->orden, pri->frase );
	pri = pri->siguiente;
}

void listar( void ) {
	celda *aux;

	if( pri == sig ) return;
	puts( "\n" );
	aux = pri;
	do {
		printf( "Nro: %3d * %s\n", aux->orden, aux->frase );
		aux = aux->siguiente;
	} while( aux != sig );
}
