#include <iostream>  // P02-05.cpp
#include <iomanip>

using namespace std;

class Tiempo {
    int hora;
    int minuto;
  public:
    Tiempo(int h=0, int m=0) : hora(h), minuto(m) {}
    void Mostrar();
    Tiempo operator+(Tiempo h);
};

Tiempo Tiempo::operator+(Tiempo h) {
  Tiempo temp;
  temp.minuto = minuto + h.minuto;
  temp.hora = hora + h.hora;
  if(temp.minuto >= 60) {
    temp.minuto -= 60;
    temp.hora++;
  }
  return temp;
}

void Tiempo::Mostrar() {
  cout << setfill('0') << setw(2) << hora << ":" << setw(2) << 
  minuto << endl;
}

int main() {
  Tiempo Ahora(12,24), T1(4,45);
  T1 = Ahora + T1;
  T1.Mostrar();
  return 0;
}		
