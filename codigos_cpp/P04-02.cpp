#include <iostream>  // P04-02.cpp

using namespace std;

class ClaseA {
  public:
    ClaseA(int a=10) : datoA(a)
      {cout << "Constructor de A" << endl;}
    int LeerA() { return datoA; }
  protected:
    int datoA;
};

class ClaseB : public ClaseA {
  public:
    ClaseB(int a=10, int b=20) : ClaseA(a), datoB(b)
      {cout << "Constructor de B" << endl;}
    int LeerB() { return datoB; }
    void incAB() { datoA++; datoB++; }
  protected:
    int datoB;
};

int main()
{
  ClaseB objeto1;
  cout << "datoA = " << objeto1.LeerA() <<
          ", datoB = " << objeto1.LeerB() << endl;
  ClaseB objeto2( 100, 200);
  cout << "datoA = " << objeto2.LeerA() <<
          ", datoB = " << objeto2.LeerB() << endl;
  objeto2.incAB();
  cout << "datoA = " << objeto2.LeerA() <<
          ", datoB = " << objeto2.LeerB() << endl;
  return 0;
}
