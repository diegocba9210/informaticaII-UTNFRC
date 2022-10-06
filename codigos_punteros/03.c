#include <string.h>
#include <stdio.h>

int main( void ) {
   char *p1;
   char c[80];
   p1 = c;
   do {
     gets( c );
     while( *p1 ) printf( "%c", *p1++ );
     printf( "\n" );
   } while( strcmp(c, "fin") );
}
