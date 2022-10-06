#include <stdio.h>

int mcd( int m, int n ); 

int main( void ) {
  
  int m, n;
  
  printf( "Ingrese los numeros a calcular el MCD: " );
  scanf( "%d %d", &m, &n );

  if( (m >= 0) && (n >= 0) )
    printf( "El MCD de %d y %d es: %d\n", m, n, mcd( m, n ) );
  else
    printf( "Los numeros deben ser positivos\n" );

  return 0;
}

int mcd( int m, int n ) {
  if( !(m%n) ) 
    return n;
  else
    return mcd( n, m%n );
}
