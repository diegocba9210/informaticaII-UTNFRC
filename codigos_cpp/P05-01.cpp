#include <iostream>  // P05-01.cpp

using namespace std;

class Base {                               // clase base
  public:
  void show() { cout << "Base" << endl; }  // funci�n normal
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

  ptr = &dv1;           // direcci�n de dv1 en el puntero
  ptr->show();          // ejecuta show()
  ptr = &dv2;           // direcci�n de dv2 en el puntero
  ptr->show();          // ejecuta show()
}
