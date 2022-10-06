#include <stdio.h>

int main( void ) {
  int val[2][3] = { 10, 11, 12, 13, 14, 15 };
  
  printf( "val[0][0]    : %d\n", val[0][0] );
  printf( "val[0][1]    : %d\n", val[0][1] );
  printf( "val[0][2]    : %d\n", val[0][2] );
  printf( "val[1][0]    : %d\n", val[1][0] );
  printf( "val[1][1]    : %d\n", val[1][1] );
  printf( "val[1][3]    : %d\n", val[1][2] );
  printf( "\n" );

  printf( "*val[0]      : %d\n", *val[0] );
  printf( "*(val[0]+1)  : %d\n", *(val[0]+1) );
  printf( "*(val[0]+2)  : %d\n", *(val[0]+2) );
  printf( "*val[1]      : %d\n", *val[1] );
  printf( "*(val[1]+1)  : %d\n", *(val[1]+1) );
  printf( "*(val[1]+2)  : %d\n", *(val[1]+2) );
  printf( "\n" );

  printf( "**val )      : %d\n", **val );
  printf( "*(*val+1)    : %d\n", *(*val+1) );
  printf( "*(*val+2)    : %d\n", *(*val+2) );
  printf( "*(*(val+1))  : %d\n", *(*(val+1)) );
  printf( "*(*(val+1)+1): %d\n", *(*(val+1)+1) );
  printf( "*(*(val+1)+2): %d\n", *(*(val+1)+2) );
} 
