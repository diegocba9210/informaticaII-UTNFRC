#include <iostream>  // P02-10.cpp

using namespace std;

void duplicado(int &a, int *b, int c) {
  a*=2;
  *b*=2;
  c*=2;
}

int main () {
  int x=1, y=3, z=7;
  cout << "Valor de las variables definidas" << endl;
  cout << "x = " << x << "  y = " << y << "  z = " << z << endl << endl;
  duplicado( x, &y, z );
  cout << "Después de la llamada a la función duplicado" << endl;
  cout << "x = " << x << "  y = " << y << "  z = " << z << endl;
  return 0;
}
