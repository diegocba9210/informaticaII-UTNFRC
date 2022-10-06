#include <iostream>  // P01-04.cpp
#include <math.h>

using namespace std;

class complejo{
    double re, im;
  public:
    // Constructor
    complejo( double preal=0.0 , double pimag=0.0 ) : re(preal), im(pimag) {};
    // Constructor de copia
    complejo( const complejo &cp ) : re(cp.re), im(cp.im) {}
    void print();
    char signo();
};

int main( void ) {
  complejo num1( 2.1, 3.5 );
  complejo num2( num1 );
  cout << "num1: "; num1.print(); cout << endl;
  cout << "num2: "; num2.print(); cout << endl;
}

void complejo::print() {
  cout << re << " " << signo() << "j " << fabs( im );
}

char complejo::signo() {
  if( im >= 0 )
    return( '+' );
  else
    return( '-' );
}
