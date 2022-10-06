/* Programa que inicializa un puerto serie abriéndolo como archivo,
   obtiene el estado de modem y lo imprime,  a continuación baja y 
   sube las líneas DTR y RTS mostrando los códigos resultantes a
   partir de la lectura de estado de modem. */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>     /* Definiciones de control de archivos */
#include <errno.h>     /* Definiciones de control de errores */
#include <sys/ioctl.h> /* Constantes para función ioctl */

void imprimestado( int estado, char *puerto ); 

int main( void ) {
  int fd, estado, resultado;
  char puerto[] = "/dev/ttyS0"; // COM1
  long tiempo = 500000, i;

  fd = open(puerto, O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1) {
    perror("open_port");
    exit( 1 );
  }

  estado = ioctl( fd, TIOCMGET, (int) &resultado );
  if( estado == -1 ) {
    perror("ioctl");
    exit( 1 );
  }

  imprimestado( resultado, puerto );
  usleep( tiempo );

  for( i=0; i<10; i++ ) {
    printf( "Cambiando RTS\n" );
    resultado ^= TIOCM_RTS;
    estado = ioctl( fd, TIOCMSET, (int) &resultado );
    if( estado == -1 ) { 
      perror("ioctl"); 
      exit( 1 );
    }

    estado = ioctl( fd, TIOCMGET, (int) &resultado );
    if( estado == -1 ) {
      perror("ioctl");
      exit( 1 );
    }
    imprimestado( resultado, puerto );
    usleep( tiempo );

    printf( "Cambiando DTR\n" );
    resultado ^= TIOCM_DTR;
    estado = ioctl( fd, TIOCMSET, (int) &resultado );
    if( estado == -1 ) { 
      perror("ioctl"); 
      exit( 1 );
    }

    estado = ioctl( fd, TIOCMGET, (int) &resultado );
    if( estado == -1 ) { 
      perror("ioctl"); 
      exit( 1 ); 
    }
    imprimestado( resultado, puerto );
    usleep( tiempo );
  }
  close( fd );
}

void imprimestado( int estado, char *puerto ) {
  printf( "Estado puerto %s:  ", puerto );
  if( estado & TIOCM_DTR ) printf( "DTR " ); else printf( "    " );
  if( estado & TIOCM_RTS ) printf( "RTS " ); else printf( "    " );
  if( estado & TIOCM_DSR ) printf( "DSR " ); else printf( "    " );
  if( estado & TIOCM_CTS ) printf( "CTS " ); else printf( "    " );
  if( estado & TIOCM_CD  ) printf( "CD "  ); else printf( "   " );
  if( estado & TIOCM_RI  ) printf( "RI "  ); else printf( "   " );
  printf( "\n" );
}  
