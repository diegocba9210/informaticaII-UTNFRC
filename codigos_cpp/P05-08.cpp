#include <iostream>  // P05-08.cpp
using namespace std;
class medingl {
    int pies;
    float pulg;
  public:
    medingl(int ft, float in)  { pies = ft; pulg = in; }
    void showdist() { cout << pies << "\' " << pulg << '\"'; }
    float cuadr();
};

float medingl::cuadr() { 
  float fltfeet = pies + pulg / 12; 
  float feetsqrd = fltfeet * fltfeet; 
  return feetsqrd;                   
}

int main( void ) {
  medingl dist(3, 6.0);        
  float sqft = dist.cuadr();  // Esto a veces no es lo que se quiere 
  cout << "Distancia = "; dist.showdist();
  cout << "\nCuadrado = " << sqft << " pies cuadrados\n";
}
