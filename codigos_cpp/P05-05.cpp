#include <iostream>  // P05-05.cpp

using namespace std;

template <class atype>
int find( atype* array, atype value, int size ) {
  for(int j=0; j<size; j++)
    if(array[j]==value)
      return j;
    return -1;
}


char chrArr[] =   {1, 3, 5, 9, 11, 13}; // arreglo
char ch = 5;                            // valor a encontrar
int intArr[] =    {1, 3, 5, 9, 11, 13};
int in = 6;
long lonArr[] =   {1L, 3L, 5L, 9L, 11L, 13L};
long lo = 11L;
double dubArr[] = {1.0, 3.0, 5.0, 9.0, 11.0, 13.0};
double db = 4.0;

int main( void ) {
  cout << " 5 en Arreglo char:   índice = " << find(chrArr, ch, 6);
  cout << "\n 6 en Arreglo int:    índice = " << find(intArr, in, 6);
  cout << "\n11 en Arreglo long:   índice = " << find(lonArr, lo, 6);
  cout << "\n 4 en Arreglo double: índice = " << find(dubArr, db, 6);
  cout << "\n";
}
