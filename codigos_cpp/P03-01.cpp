#include <iostream>  // P03-01.cpp
#include <assert.h>

using namespace std;

int main() {
	int *a;
	char *b;
	float *c;
	struct stPunto { float x, y; } *d;
	a = new int; 
	assert( a );
	b = new char;
	assert( b );
	c = new float;
	assert( c );
	d = new stPunto;
	assert( d );
	*a = 10;
	*b = 'a';
	*c = 10.32;
	d->x = 12; d->y = 15;
	cout << "a = " << *a << endl;
	cout << "b = " << *b << endl;
	cout << "c = " << *c << endl;
	cout << "d = (" << d->x << ", " << d->y << ")" << endl;

	delete a; 
	delete b;  
	delete c; 
	delete d;
	return 0;
}
