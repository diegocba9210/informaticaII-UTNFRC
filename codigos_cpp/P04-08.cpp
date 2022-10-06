#include <iostream>  // P04-08.cpp

using namespace std;

class ClaseA {
  public:
    ClaseA() : valorA(10) {}
    int LeerValor() const {return valorA;}
  protected:
    int valorA;
};

class ClaseB {
  public:
    ClaseB() : valorB(20) {}
    int LeerValor() const {return valorB;}
  protected:
    int valorB;
};

class ClaseC : public ClaseA, public ClaseB {};

int main()
{
  ClaseC CC;
  cout << CC.LeerValor() << endl;
  // Produce un error de compilación ya que hay ambigüedad.
  // cout << CC.ClaseA::LeerValor() << endl;
  return 0;
}
