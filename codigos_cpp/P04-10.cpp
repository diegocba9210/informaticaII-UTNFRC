#include <iostream>  // P04-10.cpp
#include <string.h>

using namespace std;

class Persona {
  public:
    Persona(char *n) { strcpy(nombre, n); }
    const char *LeeNombre() { return nombre; }
  protected:
    char nombre[30];
};

class Empleado : virtual public Persona {
  public:
    Empleado(char *n, int s) : Persona(n), salario(s) {}
    int LeeSalario() const { return salario; }
    void ModificaSalario(int s) { salario = s; }
  protected:
    int salario;
};

class Estudiante : virtual public Persona {
  public:
    Estudiante(char *n, float no) : Persona(n), nota(no) {}
    float LeeNota() const { return nota; }
    void ModificaNota(float no) { nota = no; }
  protected:
    float nota;
};

class Becario : public Empleado, public Estudiante {
  public:
    Becario(char *n, int s, float no) :
      Empleado(n, s), Estudiante(n, no), Persona(n) {}
};

int main() 
{
  Becario Admin1("Juan A. Pérez", 1000, 7);
  cout << "Becarios de Administración: " << endl;
  cout << Admin1.LeeNombre() << "," << Admin1.LeeSalario() << "," << 
  Admin1.LeeNota() << endl;
  return 0;
}
