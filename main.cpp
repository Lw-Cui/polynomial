#include <iostream>
#include "polynomial.h"
using namespace std;

int main(int args, char **agrv) { 
	polynomial p1, p2;

	for (int i = 0; i < 5; i++)
		p1.insert(i, i + 1);
	p1 = p1.negative();
	p1.print();

	for (int i = 7; i > 4; i--)
		p2.insert(i, i - 1);
	p2.print();

	//polynomial p3 = p4.add(p2);
	p2 = p2.multiply(p1);
	p2.print();
	
	return 0;
}
