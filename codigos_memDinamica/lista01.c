/*   Inserción, eliminación y listado en una lista enlazada simple    */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct molde{
	char linea[80];
	struct molde *siguiente;
} celda;

celda *actual, *primero, *anterior;

void borrar( void );
void listar( void );
int insertar( void );

int main( void ) {
	char operac;
	actual = primero = NULL;
	do {
		printf( "\nOperación [Inser, Listar, Borrar, Salir]: " );
		operac = getchar(); getchar();
		switch( toupper( operac ) ) {
			case 'I': { puts( "" ); insertar(); }
			break;
			case 'B': { puts( "" ); borrar(); }
			break;
			case 'L': listar();
			break;
			case 'S': return 0;
			default: continue;
		}
	} while( 1 );
	return 0;
}

void listar( void ) {
	printf( "\n\n     Impresión de la lista\n\n" );
	actual = primero;
	while( actual != NULL ) {
		printf( "Valor: %s\n", actual->linea );
		actual = actual->siguiente;
	}
}

void borrar( void ) {
	char lin[80];
	int encontrado = 0;

	printf( "\nElemento a eliminar: " );
	scanf( "%s", lin );
	getchar();
	if( strlen(lin) == 0 )
		return;
	actual = anterior = primero;

	while( (actual != NULL) && !encontrado ) {
		if( strcmp(actual->linea, lin ) != 0 ) {
			anterior = actual;
			actual = actual->siguiente;
		}
		else {
			encontrado = 1;
			break;
		}
	}
	if( encontrado ) {
		if( actual == primero )
			primero = primero->siguiente;
		else
		anterior->siguiente = actual->siguiente;
	}
	else
		printf( "\nNo se encontró el elemento solicitado\n" );
}

int insertar( void ) {
	celda  *aux;
	actual = anterior = primero;
	aux = (celda *) malloc( sizeof( celda ) );
	if( !aux ) {
		printf( "Memoria insuficiente para inserción\n" );
		exit(1);
	}
	printf( "\nElemento a ingresar: " );
	scanf( "%s", aux->linea );
	getchar();
	while((actual != NULL) && (strcmp(aux->linea, actual->linea) > 0)){
		anterior = actual;
		actual = actual -> siguiente;
	};

	/* El primero a insertar */
	if( primero == NULL ) {
		aux->siguiente = NULL;
		primero = aux;
		return 0;
	}

	/* A insertar en el primer lugar */
	if( actual == primero ) {
		aux->siguiente = primero;
		primero = aux;
		return 0;
	}

	/* A insertar al medio o final */
	aux->siguiente = actual;
	anterior->siguiente = aux;
	return 0;
}
