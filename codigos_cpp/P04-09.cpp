#include <iostream>  // P04-09.cpp

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

class ClaseC : public ClaseA, public ClaseB {
  public:
    int LeerValor() const {return ClaseA::LeerValor();}
};

int main() {
  ClaseC CC;
  cout << CC.LeerValor() << endl;
  cout << CC.ClaseB::LeerValor() << endl;
  return 0;
}
