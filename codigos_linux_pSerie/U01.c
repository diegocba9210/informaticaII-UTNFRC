/* Programa que inicializa un puerto serie abriéndolo como archivo.
   Imprime la velocidad y características de transmisión actuales.
   Configura la velocidad y características de transmisión e imprime
   el estado en que queda el puerto. */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 		/* Definiciones de control de archivos */
#include <errno.h> 		/* Definiciones de control de errores */
#include <sys/ioctl.h> 	/* Constantes para ioctl */
#include <termios.h> 	/* Estructura de control termios */

void estadolinea( char *puerto, struct termios opciones );

int main( void ) {
  int fd;
  char puerto[] = "/dev/ttyS0"; // COM1
  struct termios opciones;

  fd = open(puerto, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
  if (fd == -1) {
    perror("open_port");
    exit( 1 );
  }
  else 
    fcntl(fd, F_SETFL, 0); // funciona en forma síncrona
                           // con FNDELAY lo hace en forma asíncrona

  // Estado de linea por la estructura termios
  tcgetattr( fd, &opciones );
  printf( "Antes de configurar: \n" ); 
  estadolinea( puerto, opciones );

  // Fijando velocidad del puerto
  cfsetispeed( &opciones, B2400 );

  // Habilitación del receptor y modo local
  opciones.c_cflag |= (CLOCAL | CREAD);

  // Tamaño de palabra
  opciones.c_cflag &= ~CSIZE; /* Enmascara bits de tamaño de palabra */
  opciones.c_cflag |= CS8;    /* Selecciona 8 bits */

  // Esto es para fijar 1 stop bit
  opciones.c_cflag &= ~CSTOPB;

  // Esto es para fijar 2 stop bits.
  //opciones.c_cflag |= CSTOPB;

  // Esto es para fijar NO paridad (N)
  opciones.c_cflag &= ~PARENB;

  // Esto es para fijar paridad par (E)
  //opciones.c_cflag |= PARENB;
  //opciones.c_cflag &= ~PARODD;

  // Esto es para fijar paridad impar (O)
  //opciones.c_cflag |= PARENB;
  //opciones.c_cflag |= PARODD;

  // Escritura de la configuración en el puerto
  tcsetattr( fd, TCSANOW, &opciones );

  // Lectura de la configuración del puerto
  tcgetattr( fd, &opciones );

  printf( "Después de configurar:\n" ); 
  estadolinea( puerto, opciones );

  close( fd );
}

void estadolinea( char *puerto, struct termios opciones ) {
  int speed;

  printf( "%s: ", puerto );
  // Bits de cada palabra
  if( (opciones.c_cflag & CSIZE) == CS5) printf( "5" );
  if( (opciones.c_cflag & CSIZE) == CS6) printf( "6" );
  if( (opciones.c_cflag & CSIZE) == CS7) printf( "7" );
  if( (opciones.c_cflag & CSIZE) == CS8) printf( "8" );

  // Paridad
  if( (opciones.c_cflag & PARENB) == 0) printf( "N" );
  else {
    if( (opciones.c_cflag & PARODD) == PARODD) printf( "O" );
    else printf( "E" );  // paridad par
  }

  // Bits de parada
  if( (opciones.c_cflag & CSTOPB) == CSTOPB) printf( "2" );
  else printf( "1" );

  // Velocidad de transmisión
  printf( " " );
  speed = cfgetispeed( &opciones ); 
  switch( speed ) {
    case B50: printf( "50" ); break;
    case B75: printf( "75" ); break;
    case B110: printf( "110" ); break;
    case B134: printf( "134" ); break;
    case B150: printf( "150" ); break;
    case B200: printf( "200" ); break;
    case B300: printf( "300" ); break;
    case B600: printf( "600" ); break;
    case B1200: printf( "1200" ); break;
    case B1800: printf( "1800" ); break;
    case B2400: printf( "2400" ); break;
    case B4800: printf( "4800" ); break;
    case B9600: printf( "9600" ); break;
    case B19200: printf( "19200" ); break;
    case B38400: printf( "38400" ); break;
    case B57600: printf( "57600" ); break;
    case B115200: printf( "115200" ); break;
    default: printf ( "Error" ); break;
  }
  printf( " bps\n" );
}
