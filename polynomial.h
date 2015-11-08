#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

class unit;

class polynomial {
public:
	polynomial();

	void push(int base, int exp);
	void print() const;

	polynomial add(const polynomial &) const;
private:
	unit *beg;
};

class unit {
friend class polynomial;
private:
	unit(int base, int exp, unit *p = NULL);

	unit *next;
	int exp;
	int coe;
};

#endif