#include <iostream> // P01-02.cpp
#include <math.h>

using namespace std;

class complejo {
    double re, im;
    char signo();
  public:
    complejo( double preal = 0.0, double pimag = 0.0 );
    ~complejo() {}
    void print();
};

int main( void ) {
  complejo num1( 2.1, 3.5 ), num2( 3.3 ), res;
  cout << "Primer complejo: " ; num1.print() ; cout << endl;
  cout << "Segundo complejo: " ; num2.print() ; cout << endl;
  cout << "Resultado: " ; res.print() ; cout << endl;
}

complejo::complejo( double preal, double pimag ) {
  re = preal;
  im = pimag;
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
