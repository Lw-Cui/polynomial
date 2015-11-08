#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
#include <vector>

class nomomial {
public:
	nomomial(int base, int exp);
	void print();
private:
	int exp;
	int base;
};

class polynomial {
public:
	void add();
private:
};

#endif