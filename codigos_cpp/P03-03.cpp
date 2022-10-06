#include <iostream>  // P03-03.cpp

using namespace std;

int main( void ) {
  double pi = 3.1416926;
  double e = 2.71828;

  const double *num = &pi;  // Puntero a constante
  cout << "El valor de PI es: " << *num << endl;
  
  // Esto es un error, el valor no se puede modificar
  *num = 2.0; 
  num = &e;    // Puede cambiar el lugar donde apunta
  cout << "El valor de e es: " << *num << endl;
  double *const statnum = &pi; // Puntero constante
  cout << "El valor de PI es: " << *statnum << endl;
  
  // Esto es un error, no puedo cambiar adonde apunta
  statnum = &e;

  // Puntero constante a constante
  const double *const pten = &pi; // Punt. 
  pten = &pi;        // Esto da error
  *pten = 3.1;       // Esto también da error
}
