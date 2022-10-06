#include <stdio.h>

void imprimestr( char **frase );

int main( void ) {
  char fr[] = "Frase de prueba", *punt;
  punt = fr;
  printf( "Dirección puntero: %p\n", punt );
  imprimestr( &punt );
  printf( "Dirección puntero: %p\n", punt );
  imprimestr( &punt );
  printf( "Dirección puntero: %p\n", punt );
}

void imprimestr( char **frase ) {
  int i;
  printf( "    CONTENIDO\n" );
  for( i = 0; i < 20; i++ ) {
    putchar( **(frase)++ );  /*  Forma 1, diapo 34 */
  }

/*    putchar( **(frase)++ );    Forma 1, diapo 34 */
/*    putchar( *(*frase)++ );    Forma 2, diapo 36 */
/*    putchar( (**frase)++ );    Forma 3, diapo 38 */
  putchar( '\n' );
}
