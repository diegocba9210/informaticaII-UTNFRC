#include <stdio.h>

void puts1( char frase[] ); 
void puts2( char *frase ); 

int main( void ) {
  char *cadena = "Informática II - UTN";

  printf( "Dos formas de puts\n\n" );
  puts1( cadena );
  puts2( cadena );
}

void puts1( char frase[] ) {
  register int t;
  for( t=0; frase[t]; t++ )
    putchar( frase[t] );
  putchar( '\n' );
}

void puts2( char *frase ) {
  while( *frase ) {
    putchar( *frase );
    frase++;
  }
  putchar( '\n' );
}
