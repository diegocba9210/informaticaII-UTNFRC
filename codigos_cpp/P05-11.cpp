#include <iostream>  // P05-11.cpp

using namespace std;

class beta;

class alpha {
    friend class beta;
    beta* bptr1;           // punteros a beta
    beta* bptr2;
    int adata;
  public:
    alpha();               // constructor (definido después de beta)
    void afunc();          // función (definida después de beta)
    void showa();
};

class beta {
    friend class alpha;
    alpha* aptr;
    int bdata;
  public:                  // inicializa el puntero a alfa
    beta(alpha* ap) : aptr(ap) { cout<< "Constructor de beta"<< endl; }
    void bfunc() {
      aptr->adata = 3;     // accede datos privados de alfa
    }
};

alpha::alpha() {             // constructor de alfa
  bptr1 = new beta(this);
  cout << "Constructor de alpha, generé puntero bptr1 a beta" <<  endl;
  bptr2 = new beta(this);
  cout << "Constructor de alpha, generé puntero bptr2 a beta" << endl;
}

void alpha::afunc() {        // función de alfa
  bptr1->bdata = 4;          // accede datos privados de beta
  bptr2->bdata = 5;          // debe ser definida después de beta
}

void alpha::showa() {
  cout << endl << "Muestra de datos de alpha" << endl;
  cout << "btpr1->bdata: " << bptr1->bdata << endl;
  cout << "btpr2->bdata: " << bptr2->bdata << endl;
}

int main( void ) {
  alpha objA;
  objA.afunc();
  objA.showa();
}

