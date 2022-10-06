#include <stdio.h>

unsigned long int factorial( int n ); 

int main( void ) {
  
  int n;
  
  printf( "Ingrese el numero a calcular factorial: " );
  scanf( "%d", &n );

  if( n >= 0 )
    printf( "El factorial de %d es: %lu\n", n, factorial( n ) );
  else
    printf( "El numero debe ser 0 o positivo\n" );

  return 0;
}

unsigned long int factorial( int n ) {
  if( n == 0 ) 
    return 1;
  else
    return n * factorial( n - 1 );
}
