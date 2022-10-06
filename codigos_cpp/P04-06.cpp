#include <iostream>  // 04-06
using namespace std;

class ClaseA {
  public:
    ClaseA(int a=10) : datoA(a) {cout << "Constructor de A" << endl;}
    int LeerA() { return datoA; }
  protected:
    int datoA;
};

class ClaseB : public ClaseA {
  public:
    ClaseB(int a=10, int b=20) : ClaseA(a), datoB(b) {cout << "Constructor de B" << endl;}
    int LeerB() { return datoB; }
  protected:
    int datoB;
};

class ClaseC : public ClaseB {
  public:
    ClaseC(int a=10, int b=20, int c=30) : ClaseB(a, b), datoC(c)
      {cout << "Constructor de C" << endl;}
    int LeerC() { return datoC; }
    void LeerT() { cout << "datoA: " << datoA << ", datoB: " <<
                   datoB << ", datoC: " << datoC << endl; }
    void incrC( int a, int b, int c ) { datoA += a; datoB += b; datoC += c; }
  protected:
    int datoC;
};

int main()
{
  ClaseC objetoC( 100, 200, 300);
  cout << "objetoC" << endl;
  objetoC.LeerT();
  objetoC.incrC( 5, 10, 15 );
  cout << "Después del incremento" << endl;
  objetoC.LeerT();

  ClaseC objetoM( 50, 60, 70 );
  cout << "objetoM" << endl;
  cout << "datoA = " << objetoM.LeerA() << ", datoB = " << objetoM.LeerB() <<
          ", datoC = " << objetoM.LeerC() << endl;
  return 0;
}
