#include <iostream>
#include "polynomial.h"
#define INF (1 << 20)

unit::unit(int coe, int exp, unit *p)
	:coe(coe), exp(exp), next(p) {

}

polynomial::polynomial() {
	beg = new unit(0, INF, new unit(0, -INF));
}

void polynomial::push(int coe, int exp) {
	unit *p = beg;
	while (p->next->exp > exp)
		p = p->next;

	if (p->exp == exp)
		p->coe += coe;
	else
		p->next = new unit(coe, exp, p->next);
}

void polynomial::print() const {
	for (unit *p = beg; p != NULL; p = p->next)
		if (p->coe) {
			if (p != beg->next) std::cout << " + ";
			 std::cout << p->coe << "x^" << p->exp;
		}
	std::cout << std::endl;
}