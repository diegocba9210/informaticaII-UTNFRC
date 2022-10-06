#include <stdio.h>

int main( void ) {
  int x, *p;
  x = 10;
  p = x;
  printf( "El valor de x es: %d\n", *p );
}
