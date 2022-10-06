#include <iostream>  // P04-05.cpp

using namespace std;

class ClaseA {
  public:
    ClaseA(int a=10) : datoA(a) {cout << "Constructor de A" << endl;}
    int LeerA() { return datoA; }
  protected:
    int datoA;
};

class ClaseB : private ClaseA {
  public:
    ClaseB(int a=12, int b=22) : ClaseA(a), datoB(b)
      {cout << "Constructor de B" << endl;}
    int LeerB() { return datoB; }
    void LeerT() { cout << "datoA = " << datoA <<
                   ", datoB = " << datoB << endl; }
    void incAB( int a, int b ) { datoA += a; datoB += b; }
  protected:
    int datoB;
};


int main()
{
  ClaseB objeto;
  objeto.LeerT();
  objeto.incAB( 7, 8 );
  cout << "Después del incremento" << endl;
  objeto.LeerT();
  return 0;
}
