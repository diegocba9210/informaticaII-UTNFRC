#include <stdio.h>

int main( void ) {
  int x, *p;
  x = 10;
  *p = x;

  printf( "El valor de x es: %d\n", x );
  printf( "La direccion de x es: %p\n\n", &x );

  printf( "El contenido donde apunta p es: %d\n", *p );
  printf( "La direccion donde apunta p es: %p\n\n", p );

  x++;
  printf( "El valor de x es: %d\n", x );
  printf( "El contenido donde apunta p es: %d\n", *p );
}

