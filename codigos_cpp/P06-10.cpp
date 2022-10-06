#include <iostream>  // P06-10.cpp

using namespace std;

int divide( int divisor, int dividend ) throw ( const char* );
// Divide el divisor con el  dividendo que debe ser !=0

int main( void ) {
  try {
    int result = divide( 50, 2 );
    cout << "División(" << 50 << ", " << 2 << ") da " << result << endl;
    result = divide( 50, 0 );
    cout << "divide(" << 50 << ", " << 0 << ") da " << result << endl;
  }
  catch (const char* msg) {
    cout << "Epa, gran error!: " << msg << endl;
  }
  return 0;
}

int divide( int divisor, int dividend ) throw ( const char* ) {
  if (dividend == 0)
    throw (const char*)"Se intentó una división por cero";
    // No debemos preocuparnos por una división por cero
  return divisor/dividend;
}
