#include <iostream>
#include "polynomial.h"
using namespace std;

int main(int args, char **agrv) { 
	polynomial p;

	for (int i = 0; i < 5; i++)
		p.push(i, i + 1);
	p.print();
	return 0;
}