#include <iostream>  // P04-04.cpp

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
    ClaseB(int a=10, int b=20) : ClaseA(a), datoB(b)
      {cout << "Constructor de B" << endl;}
    int LeerB() { return datoB; }
  protected:
    int datoB;
};


int main()
{
  ClaseB objeto;
  cout << "datoA = " << objeto.LeerA() <<
          ", datoB = " << objeto.LeerB() << endl;
  return 0;
}
