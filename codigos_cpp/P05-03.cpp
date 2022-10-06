#include <iostream>  // P05-03.cpp

using namespace std;

class Base {                               // clase base
  public:
  virtual void show() { cout << "Base" << endl; } // función virtual
};
class Derv1 : public Base {                // clase derivada 1
  public:
    void show() { cout << "Deriv1" << endl; }
};
class Derv2 : public Base {                // clase derivada 2
  public:
    void show() { cout << "Deriv2" << endl; }
};
int main( void ) {
  Base* arrBase[2]; 	// arreglo de punteros a clase Base
  Derv1 dv1; 		// objeto de clase derivada 1
  Derv2 dv2; 		// objeto de clase derivada 2
  arrBase[0] = &dv1; 	// dirección de dv1 en el arreglo
  arrBase[1] = &dv2; 	// dirección de dv2 en el arreglo
  for(int j=0; j<2; j++ ) {	// ejecuta show() para todos
    arrBase[j]->show();   	// los elementos del arreglo
  }
}
