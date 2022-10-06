#include <iostream>  // P05-09.cpp
using namespace std;
class medingl {
    int pies;
    float pulg;
  public:
    medingl(int ft, float in)  { pies = ft; pulg = in; }
    void showdist() { cout << pies << "\' " << pulg << '\"'; }
    friend float square( medingl );    // función amiga
};

float square ( medingl mi ) { 
  float fltfeet = mi.pies + mi.pulg / 12; 
  float feetsqrd = fltfeet * fltfeet; 
  return feetsqrd;                   
}

int main( void ) {
  medingl dist(3, 6.0);        
  float sqft = square( dist );     // Aparece como una función común
  cout << "Distancia = "; dist.showdist();
  cout << "\nCuadrado = " << sqft << " pies cuadrados\n";
}
