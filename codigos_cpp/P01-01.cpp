#include <iostream>  // P01-01.cpp
#include <math.h>

using namespace std;

class complejo {
    double re, im;
    char signo();
  public:
    complejo( double preal, double pimag );
    ~complejo();
    void sumac( complejo a, complejo b );
    void restac( complejo a, complejo b );
    void print();
};

int main( void ) {
  complejo num1( 2.1, 3.5 ), num2( 3.3, -0.6 ), res( 0.0, 0.0 );
  cout << "Primer complejo: " ; num1.print() ; cout << endl;
  cout << "Segundo complejo: " ; num2.print() ; cout << endl;
  res.sumac( num1, num2 );
  cout << "Suma : " ; res.print() ; cout << endl;
  res.restac( num1, num2 );
  cout << "Resta : " ; res.print() ; cout << endl;
}

complejo::complejo( double preal, double pimag ) {
  re = preal;
  im = pimag;
  cout << "Ejecutando el constructor (";
  cout << re << ", " << im << ")" << endl;
}

complejo::~complejo() {
  cout << "Ejecutando el destructor (";
  cout << re << ", " << im << ")" << endl;
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

void complejo::sumac( complejo a, complejo b ) {
  re = a.re + b.re;
  im = a.im + b.im;
}

void complejo::restac( complejo a, complejo b ) {
  re = a.re - b.re;
  im = a.im - b.im;
}
