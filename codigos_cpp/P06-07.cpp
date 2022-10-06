#include <iostream>  // P06-07.cpp
#include <fstream>
using namespace std;
int main( void )
{
  char linea[80];
  ofstream fp;

  fp.open( "miarchivo.txt", ios::out );
  if( !fp ) {
    cout << "ERROR en apertura de archivo" << endl;
    exit(1);
  }                // traslada entrada por teclado al archivo
  while(1) { 	    // hasta que ingresamos "." en una línea.
    cin.getline( linea, 80, '\n' );   
    if( (strlen(linea)==1) && (linea[0]=='.') )
      break;
    fp << linea << endl;
  }
  fp.close();
  return 0;
}
