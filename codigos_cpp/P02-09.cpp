#include <iostream>  // P02-09.cpp
using namespace std;
int main ()
{
  double a; 		  // a reserva espacio
  double *b = &a; 	  // b puntero que apunta a 'a'
  double &c = *b; 	  // c referencia a *b
				  // es lo mismo que:  &c = a;
  double &d = a;
  a = 3.1415926;
  cout << "Contenido de a : " << a << endl;
  cout << "Contenido de *b: " << *b << endl;
  cout << "Contenido de c : " << c << endl;
  cout << "Contenido de d : " << d << endl;
  return 0;
}
