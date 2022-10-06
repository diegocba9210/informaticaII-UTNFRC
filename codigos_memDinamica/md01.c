/* Programa que reserva memoria dinámica, la utiliza y la libera */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

int main(void) {
	char *str;

	/* Reserva memoria para un string */
	if ((str = (char *) malloc(TAM)) == NULL) {
		printf("No hay memoria suficiente \n");
		exit(1);
	}

	/* Copia "Frase de ejemplo" en la cadena */
	strcpy(str, "Frase de ejemplo");

	/* Muestra la cadena */
	printf("La cadena es: %s\n", str);

	/* Libera memoria */
	free(str);

	/* Trata de volver a mostrar la cadena */
	printf("La cadena es: %s\n", str);

	return 0;
}
