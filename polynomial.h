#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
#define INIT 100

class unit;

class polynomial {
public:
	polynomial();
	void push(int base, int exp);
	void add(const polynomial &);
	void print() const;
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