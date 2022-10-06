/* Programa que inicializa un puerto serie abriéndolo como archivo,
   a continuación inserta y quita un break en la línea de transmisión
   por el tiempo que se indique como argumento de la línea de 
   comandos */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 	/* Definiciones de control de archivos */
#include <errno.h> 	/* Definiciones de control de errores */
#include <sys/ioctl.h> 	/* Constantes para ioctl */

void imprimestado( int estado, char *puerto ); 

int main( int argc, char *argv[] ) {
  int fd, estado, resultado, i, delay;
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
  estado = ioctl( fd, TIOCSBRK, (int) &resultado );
  usleep( delay );
  estado = ioctl( fd, TIOCCBRK, (int) &resultado );
  usleep( delay );
  close( fd );
}
