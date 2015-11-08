#include <iostream>
#include "polynomial.h"
using namespace std;

int main(int args, char **agrv) { 
	polynomial p1, p2;

	for (int i = 0; i < 5; i++)
		p1.push(i, i + 1);

	for (int i = 3; i < 7; i++)
		p2.push(i, i - 1);

	polynomial p3 = p1.add(p2);
	p3.print();

	return 0;
}