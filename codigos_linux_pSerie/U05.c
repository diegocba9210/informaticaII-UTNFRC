// Programa que inicializa un puerto serie, lee el estado 
// de modem y sube y baja en forma secuencial las señales
// DTR, RTS y break

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> /* Definiciones de control de archivos */
#include <errno.h> /* Definiciones de control de errores */
#include <sys/ioctl.h> /* Constantes para ioctl */

void imprimestado( int estado, char *puerto ); 

int main( int argc, char *argv[] ) {
  int fd, estado, resultado = 0, i, delay;
  char puerto[] = "/dev/ttyS0"; // COM1

  if( argc < 2 ) {
    printf( "Uso: %s delay [us]\n", argv[0] );
    exit( 1 );
  }

  fd = open(puerto, O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1) {
    perror("open_port");
    exit( 1 );
  }

  delay = atoi( argv[1] ); 
  for( i=0; i<100; i++ ) {
    estado = ioctl( fd, TIOCSBRK, (int) &resultado );
    usleep( delay );
    resultado ^= TIOCM_DTR;
    estado = ioctl( fd, TIOCMSET, (int) &resultado );
    estado = ioctl( fd, TIOCCBRK, (int) &resultado );
    usleep( delay );
    resultado ^= TIOCM_RTS;
    estado = ioctl( fd, TIOCMSET, (int) &resultado );
  }
  close( fd );
}

void imprimestado( int estado, char *puerto ) {
  printf( "Estado puerto %s:\n", puerto );
  if( estado & TIOCM_DTR ) printf( "DTR " ); else printf( "    " );
  if( estado & TIOCM_RTS ) printf( "RTS " ); else printf( "    " );
  if( estado & TIOCM_DSR ) printf( "DSR " ); else printf( "    " );
  if( estado & TIOCM_CTS ) printf( "CTS " ); else printf( "    " );
  if( estado & TIOCM_CD  ) printf( "CD "  ); else printf( "   " );
  if( estado & TIOCM_RI  ) printf( "RI "  ); else printf( "   " );
  printf( "\n" );
}  
