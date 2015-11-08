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
	if (coe == 0)
		return;
	
	unit *p = beg;
	while (p->next->exp > exp)
		p = p->next;

	if (p->next->exp == exp)
		p->next->coe += coe;
	else
		p->next = new unit(coe, exp, p->next);
}

polynomial polynomial::add(const polynomial &p) const {
	polynomial ans;
	unit *p1 = beg, *p2 = p.beg;

	while (p1 != NULL && p2 != NULL)
		if (p1->exp > p2->exp) {
			ans.push(p1->coe, p1->exp);
			p1 = p1->next;
		} else {
			ans.push(p2->coe, p2->exp);
			p2 = p2->next;
		}

	for (; p1 != NULL; p1 = p1->next)
		ans.push(p1->coe, p1->exp);
	for (; p2 != NULL; p2 = p2->next)
		ans.push(p2->coe, p2->exp);

	return ans;
}

void polynomial::print() const {
	for (unit *p = beg; p != NULL; p = p->next)
		if (p->coe) {
			if (p != beg->next) std::cout << " + ";
			 std::cout << p->coe << "x^" << p->exp;
		}
	std::cout << std::endl;
}