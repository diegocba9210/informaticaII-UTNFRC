#include <iostream>  // P05-06.cpp

using namespace std;

class airtime
{
   int hours;              // 0 a 23
   int minutes;            // 0 a 59
  public:                    // constructor para 0, 1 o 2 arg
    airtime(int h = 0, int m = 0) : hours(h), minutes(m) {  }
    void display()          // salida a pantalla
      { cout << hours << ':' << minutes; }
    void get() {             // entrada del usuario
      char dummy;
      cin >> hours >> dummy >> minutes;
    }                    // operator + sobrecargado
    airtime operator + (airtime right) {
      airtime temp;        // objeto temporario
      temp.hours = hours + right.hours; // agregado de datos
      temp.minutes = minutes + right.minutes;
      if(temp.minutes >= 60) {     // verificación de acarreo
        temp.hours++;
        temp.minutes -= 60;
      }
      return temp;         // retorna objeto temporario por valor
    }
};

int main( void )
{
  airtime at1, at2;

  cout << "Ingrese una hora [10:00]: ";
  at1.get();

  at2 = at1 + 3;    // suma entero al objeto

  cout << "airtime + 3 = ";
  at2.display();

  // at2 = 3 + at1;   // error: illegal structure operation

}
