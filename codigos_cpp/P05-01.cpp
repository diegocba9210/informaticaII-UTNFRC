#include <iostream>  // P05-01.cpp

using namespace std;

class Base {                               // clase base
  public:
  void show() { cout << "Base" << endl; }  // función normal
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
  Derv1 dv1;            // objeto de clase derivada 1
  Derv2 dv2;            // objeto de clase derivada 2
  Base* ptr;            // puntero a la clase base

  ptr = &dv1;           // dirección de dv1 en el puntero
  ptr->show();          // ejecuta show()
  ptr = &dv2;           // dirección de dv2 en el puntero
  ptr->show();          // ejecuta show()
}
