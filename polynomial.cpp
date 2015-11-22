#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include <cstring>
#include "polynomial.h"
#define INF (1 << 20)
#define MAX 30

unit::unit(double coe,double exp, unit *n, unit *l)
	:coe(coe), exp(exp), next(n), last(l) {

}

polynomial::polynomial() {
	spare = newspace();
	end = beg = getunit(0, -INF);
}

polynomial::~polynomial() {
	destory(beg);
	destory(spare);
}

polynomial::polynomial(const polynomial &p) {
	spare = newspace();
	end = beg = getunit(0, -INF);
	for (unit *p1 = p.beg; p1 != NULL; p1 = p1->next)
		if (p1->exp != -INF)
			append(p1->coe, p1->exp);
}

polynomial &polynomial::operator=(const polynomial &p) {
	if (&p == this)
		return *this;

	destory(beg);
	destory(spare);

	spare = newspace();
	end = beg = getunit(0, -INF);
	for (unit *p1 = p.beg; p1 != NULL; p1 = p1->next)
		if (p1->exp != -INF)
			append(p1->coe, p1->exp);
}

void polynomial::destory(unit *start) {
	if (start && start->next)
		for (unit *p = start->next; p != NULL; p = p->next)
			delete p->last;
	else if (start)
		delete start;
}

unit *polynomial::insert(unit *obj, unit *dist) {
	if (dist->last) {
		dist->last->next = obj;
		obj->last = dist->last;
	}

	obj->next = dist;
	dist->last = obj;

	return obj;
}

void polynomial::del(unit *p) {
	if (beg == p) {
		beg = p->next;
		beg->last = NULL;
	} else {
		p->next->last = p->last;
		p->last->next = p->next;
	}

	p->next = spare;
	if (spare != NULL)
		spare->last = p;
}

unit *polynomial::newspace() {
	unit *p = new unit[MAX];
	for (int i = 0; i < MAX - 1; i++) {
		p[i].next = &p[i + 1];
		p[i + 1].last = &p[i];
	}
	return p;
}

unit *polynomial::getunit(double coe,double exp) {
	if (spare == NULL)
		spare = newspace();

	spare->coe = coe;
	spare->exp = exp;
	spare->next = spare->last = NULL;

	unit *p = spare;
	spare = spare->next;
	return p;
}

void polynomial::append(double coe,double exp) {
	if (coe == 0) return;

	if (end->last && end->last->exp == exp) {
		end->last->coe += coe;
		if (end->last->coe == 0) del(end->last);

	} else {
		unit *obj = getunit(coe, exp);
		insert(obj, end);
		if (end == beg) beg = obj;
	}
}


polynomial &polynomial::add(const char *str) {
	return add(atoi(str), atoi(strchr(str, '^') + 1));
}

polynomial &polynomial::add(double coe,double exp) {
	if (coe == 0) return *this;

	unit *p = beg;
	while (p->exp > exp)
		p = p->next;

	if (p->exp == exp) {
		p->coe += coe;
		if (p->coe == 0) del(p);

	} else {
		unit *obj = getunit(coe, exp);
		insert(obj, p);
		if (p == beg) beg = obj;
	}
	return *this;
}

polynomial polynomial::minus(const polynomial &p) const {
	return add(p.negative());
}

polynomial polynomial::negative() const {
	polynomial ans;
	for (unit *p = beg; p != NULL; p = p->next)
		ans.append(-p->coe, p->exp);
	return ans;
}

polynomial polynomial::add(const polynomial &p) const {
	polynomial ans;
	unit *p1 = beg, *p2 = p.beg;

	while (p1 != NULL && p2 != NULL)
		if (p1->exp > p2->exp) {
			ans.append(p1->coe, p1->exp);
			p1 = p1->next;
		} else {
			ans.append(p2->coe, p2->exp);
			p2 = p2->next;
		}

	for (; p1 != NULL; p1 = p1->next)
		ans.append(p1->coe, p1->exp);
	for (; p2 != NULL; p2 = p2->next)
		ans.append(p2->coe, p2->exp);

	return ans;
}

polynomial polynomial::multiply(const polynomial &p) const {
	polynomial ans;

	for (unit *p1 = beg; p1 != NULL; p1 = p1->next)
		for (unit *p2 = p.beg; p2 != NULL; p2 = p2->next)
			if (p1->exp != -INF && p2->exp != -INF)
				ans.add(p1->coe * p2->coe, p1->exp + p2->exp);

	return ans;
}

bool polynomial::islower(const polynomial &p) const { 
	return beg->exp < p.beg->exp;
}

void polynomial::div_and_mod(const polynomial &p, 
		polynomial &result, polynomial &remainder) const {
	remainder = *this;

	while (!remainder.islower(p)) {
		double coe = remainder.beg->coe / p.beg->coe;
		double exp = remainder.beg->exp - p.beg->exp;
		if (coe == 0) break;

		polynomial ans;
		ans.append(coe, exp);
		result.append(coe, exp);

		remainder = remainder.minus(ans.multiply(p));
	}
}

polynomial polynomial::modulo(const polynomial &p) const {
	polynomial result, remainder;
	div_and_mod(p, result, remainder);
	return remainder;
}

polynomial polynomial::divide(const polynomial &p) const {
	polynomial result, remainder;
	div_and_mod(p, result, remainder);
	return result;
}

std::ostream &operator<<(std::ostream &out, const polynomial &px) {
	for (unit *p = px.beg; p != NULL; p = p->next)
		if (p->coe) {
			if (p != px.beg) out << " + ";
			out << p->coe << "x^" << p->exp;
		}
	return out;
}
