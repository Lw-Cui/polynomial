#include <cstdio>
#include "polynomial.h"
using namespace std;

void add_and_minus(polynomial &p1, polynomial &p2) {
    cout << "p1 = " << p1 << endl << "p2 = " << p2 << endl;

	cout << "p1 + p2 = " << p1 + p2 << endl;
    cout << "p1 - p2 = " << p1 - p2 << endl;
}

void divide_and_modulo(polynomial &p1, polynomial &p2) {
    cout << "p1 = " << p1 << endl << "p2 = " << p2 << endl;

    cout << "p1 * p2 = " << p1 * p2 << endl;
	cout << "p1 / p2 = " << p1 / p2 << endl;
    cout << "p1 % p2 = " << p1 % p2 << endl;
}

int main(int args, char **agrv) { 
    polynomial p1, p2;
    
	p1.add("-2x^2").add("1x^1");
	p2.add("2x^1").add("1x^0");
    add_and_minus(p1, p2);

	p1.add("10x^4").add("1x^3");
	p2.add("5x^2");
	divide_and_modulo(p1, p2);
	return 0;
}
