// punteros a funciones  P02-08.cpp
#include <iostream>

using namespace std;
int suma( int a, int b ) { return a + b; }

int resta( int a, int b ) { return a - b; }
int ( *menos )( int, int ) = resta;

int operacion (int x, int y, int(*funallamar)( int, int )) {
  int g;
  g = (*funallamar)( x, y );
  return g;
}

int main() {
  int m, n, p;
  m = operacion( 7, 5, suma );
  n = operacion( 20, m, menos );
  p = operacion( 12, 15, resta );
  cout << "El valor de m queda: " << m << endl;
  cout << "El valor de n queda: " << n << endl;
  cout << "El valor de p queda: " << p << endl;
  return 0;
}
