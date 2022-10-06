class Persona { };  // 04-07

class Estudiante :  private Persona { };

void bailar(const Persona& p) {}      // cualquiera baila
void estudiar(const Estudiante& s) {} // solo los estudiantes
                                      // estudian

int main( void ) {
  Persona p;                      // p es una Persona
  Estudiante s;                   // s es un Estudiante

  bailar(p);                      // está bien, p is una
                                  // Persona

  bailar(s);                      // error! un Estudiante no es
}                                 // una Persona
