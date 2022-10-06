#include <iostream>  // P05-10.cpp
using namespace std;
class beta;    // necesaria para la declaración de frifunc
class alfa {
    int data;
  public:
    alfa()  { data = 3; }  // constructor
    friend int frifunc( alfa, beta );
};

class beta {
  int data;
  public:
    beta()  { data = 7; }   // constructor
    friend int frifunc( alfa, beta );
};

int frifunc( alfa a, beta b ) {
  return( a.data + b.data );
}

int main( void ) {
  alfa aa;
  beta bb;
  cout << frifunc( aa, bb ) << endl;
}
