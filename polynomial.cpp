#include <iostream>
#include "polynomial.h"

nomomial::nomomial(int base, int exp)
	:base(base), exp(exp) {

}

void nomomial::print() {
	std::cout << base << "  " << exp << std::endl;
}