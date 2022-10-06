#include <iostream>  // P02-06.cpp

using namespace std;

class airtime {
    int hours;
    int minutes;
  public:
    airtime() : hours(0), minutes(0) {}
    airtime(int h, int m) : hours(h), minutes(m) {}
    void display() const {
      cout << hours << ':' << minutes;
    }
    void get() {
      char dummy;
      cout << "\nIngrese hora (formato 12:59): ";
      cin >> hours >> dummy >> minutes;
    }
    airtime operator++ () {
      ++minutes;
      if(minutes >= 60) {
        ++hours;
        minutes -= 60;
      }
      return airtime(hours, minutes);
    }
};

int main() {
  airtime at1, at2;
  at1.get();
  
  ++at1;
  cout << "at1= "; at1.display(); cout << endl;
  
  at2 = ++at1;
  cout << "at2= "; at2.display(); cout << endl;
}
