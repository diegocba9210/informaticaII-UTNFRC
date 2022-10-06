#include <stdio.h>

unsigned long int fibonaci( int n ); 

int main( void ) {
  
  int n;
  
  printf( "Ingrese el numero a calcular Sucesion de Fibonaci: " );
  scanf( "%d", &n );

  if( n >= 0 )
    printf( "El numero de fibonaci de %d es: %lu\n", n, fibonaci( n ) );
  else
    printf( "El numero debe ser 0 o positivo\n" );

  return 0;
}

unsigned long int fibonaci( int n ) {
  if( (n == 0) || (n == 1 ) ) 
    return 1;
  else
    return fibonaci( n - 1) + fibonaci( n - 2 );
}
