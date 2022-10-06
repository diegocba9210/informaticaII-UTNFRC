/* Programa que inicializa un puerto serie abriéndolo como archivo.
   Imprime la velocidad y características de transmisión actuales.
   Configura la velocidad y características de transmisión de acuerdo
   a lo ingresado en la línea de comandos e imprime el estado en que 
   queda el puerto. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 	/* Definiciones de control de archivos */
#include <errno.h> 	/* Definiciones de control de errores */
#include <sys/ioctl.h> 	/* Constantes para ioctl */
#include <termios.h> 	/* Estructura de control termios */

void estadolinea( char *puerto, struct termios opciones );
int velocidad( int speed ); 

int main( int argc, char *argv[] ) {
  int fd;                       /* descriptor archivo del puerto */
  char puerto[12] = "/dev/ttyS"; 
  int longpal; 			/* longitud de palabra */
  struct termios opciones;

/* CONTROL DE CONSISTENCIA DE LA LINEA DE COMANDOS */
  if( argc < 4 ) {
    printf( "\nUso: %s puerto[0..3] disciplina[ej. 8N1] velocidad[bps]\n\n",
            argv[0] );
    exit(1);
  }
  strcat( puerto, argv[1] );
  printf( "Puerto: %s\n", puerto );

  if( (atoi(argv[1]) < 0) || (atoi(argv[1]) > 3) ) {
    printf( "\nEl puerto debe ser entre 0 y 3\n\n" );
    exit(1);
  }

  if( (atoi(&argv[2][0]) < 5) || (atoi(&argv[2][0]) > 8) ) {
    printf( "Chars por palabra debe estar entre 5 y 8\n" );
    exit( 1 );
  }

  if( (toupper(argv[2][1]) != 'N') && (toupper(argv[2][1]) != 'E') &&
      (toupper(argv[2][1]) != 'O') ) {
    printf( "Paridad debe ser N, E, O\n" );
    exit( 1 );
  }

  if( (atoi(&argv[2][2]) < 1) || (atoi(&argv[2][2]) > 2) ) {
    printf( "Bits de stop debe ser 1 ó 2\n" );
    exit( 1 );
  }
/* FIN CONTROL DE CONSISTENCIA DE LA LINEA DE COMANDOS */

  // Apertura del puerto
  fd = open(puerto, O_RDWR | O_NOCTTY | O_NDELAY | O_NONBLOCK);
  if (fd == -1) {
    perror("open_port");
    exit( 1 );
  }
  else 
    fcntl(fd, F_SETFL, 0); // funciona en forma sincrona

  // Lectura de estado de linea por la estructura termios
  tcgetattr( fd, &opciones );
  printf( "Antes de configurar: \n" ); 
  estadolinea( puerto, opciones );

  // Fijando velocidad del puerto
  cfsetispeed( &opciones, velocidad( atoi(argv[3]) ) );

  // Habilitación del receptor y modo local
  opciones.c_cflag |= (CLOCAL | CREAD);

  // Tamaño de palabra
  opciones.c_cflag &= ~CSIZE; /* Mask the character size bits */
  switch( atoi(&argv[2][0]) ) {
    case 5: longpal = CS5; break;
    case 6: longpal = CS6; break;
    case 7: longpal = CS7; break;
    case 8: longpal = CS8; break;
  }
  opciones.c_cflag |= longpal; 

  // Fijando la cantidad de stop bits
  if( atoi(&argv[2][2]) == 1 )
    opciones.c_cflag &= ~CSTOPB;
  else
    opciones.c_cflag |= CSTOPB;

  // Fijando la paridad
  if( toupper(argv[2][1]) == 'N' )
    opciones.c_cflag &= ~PARENB;

  if( toupper(argv[2][1]) == 'E' ) {
    opciones.c_cflag |= PARENB;
    opciones.c_cflag &= ~PARODD;
  }

  if( toupper(argv[2][1]) == 'O' ) {
    opciones.c_cflag |= PARENB;
    opciones.c_cflag |= PARODD;
  }

  // Fijación de los parámetros el puerto 
  tcsetattr( fd, TCSANOW, &opciones );

  // Obtención de los parámetros el puerto 
  tcgetattr( fd, &opciones );

  printf( "Después de configurar: \n" ); 
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

int velocidad( int speed ) { 
  switch( speed ) {
    case 50: return( B50 );
    case 75: return( B75 );
    case 110: return( B110 );
    case 134: return( B134 );
    case 150: return( B150 );
    case 200: return( B200 );
    case 300: return( B300 );
    case 600:return( B600 );
    case 1200: return( B1200 );
    case 1800: return( B1800 );
    case 2400: return( B2400 );
    case 4800: return( B4800 );
    case 9600: return( B9600 );
    case 19200: return( B19200 );
    case 38400: return( B38400 );
    case 57600: return( B57600 );
    case 115200: return( B115200 );
    default: printf ( "Error velocidad no permitida\n" ); 
             exit(1);
             break;
  }
}
