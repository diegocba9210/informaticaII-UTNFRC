/* Reserva de memoria para estructura y punteros a campos */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	double f;
	char c;
} T_EST, *EST;

EST reserv_mem( void ) {
	EST temp;
	temp = (EST) malloc( sizeof(T_EST) );
	return temp;
}

int main() {
	EST t = reserv_mem();
	int *ptr1;
	double *ptr2;
	char *ptr3;
  
	printf("\nDirección de t: %p\n",t);    
  
	t->a = 5;
	t->f = 3.5;
	t->c = 'a';

	printf("Contenido de los campos de t: %p\n",t);    
	printf( "t->a = %d , t->f = %.1f , t->c = %c\n\n", t->a, t->f, t->c );

	/* Punteros a los campos */
	ptr1 = &(t->a);
	ptr2 = &(t->f);
	ptr3 = &(t->c);

	printf("Direcciones de memoria de los campos\n");
	printf( "t->a: %p \nt->f: %p \nt->c: %p\n\n", ptr1, ptr2, ptr3 );

	/* Cambio de valores a través de indirección de punteros de campos */
	*ptr1 = 10;
	*ptr2 = 7.0;
	*ptr3 = 'b';

	printf("Después de cambiar el contenido de los campos por punteros a campos\n");
	printf( "t->a = %d  , t->f = %.1f  , t->c = %c\n\n", t->a, t->f, t->c );

	free(t);
	return 0;
}
