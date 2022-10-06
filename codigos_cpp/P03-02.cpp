#include <iostream> // P03-02.cpp

using namespace std;

int main() {
  int **tabla;
  int n = 100;
  int m = 200;
  int i;
  
  // Arreglo de punteros a int
  tabla = new int*[n];

  // n arreglos de m ints

  for(i = 0; i < n; i++)
	 tabla[i] = new int[m];
  tabla[21][33] = 123;      // Ejemplo de asignación

  cout << tabla[21][33] << endl;
  // Liberación de memoria, deshaciendo el camino hecho

  for(i = 0; i < n; i++) delete[] tabla[i];
  delete[] tabla;
  return 0;
}
