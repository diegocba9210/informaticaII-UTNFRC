#include <iostream>  // P02-04.cpp
#include <math.h>

using namespace std;

class complejo {
    double i, j;
  public:
    complejo( double a=0, double b=0 ) { i=a; j=b; }
    complejo operator+( complejo c );
    void print();
    char complejo::signo();
};

complejo complejo::operator+( complejo c ) {
  return complejo( i+c.i, j+c.j );
}

// .......

int main( void ) {
  complejo r(2,3), s(-4), su;
  su = r + s;    // representa: su = r.operator+ ( s );
  cout << "Suma de complejos: "; su.print(); cout << endl;
}

void complejo::print() {
  cout << i << " " << signo() << "j " << fabs( j );
}

char complejo::signo() {
  if( j >= 0 )
    return( '+' );
  else
    return( '-' );
}
