#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
//TO DO: COPY CONSTRUCTOR
#include <iostream>

class unit;

class polynomial {
	friend std::ostream &operator<<(std::ostream &, const polynomial &);

public:
	polynomial();
	~polynomial();

	polynomial(const polynomial &);
	polynomial &operator=(const polynomial &);
	inline polynomial operator+(const polynomial &p) const { return add(p); }
	inline polynomial operator-(const polynomial &p) const { return minus(p); }
	inline polynomial operator*(const polynomial &p) const { return multiply(p); }
	inline polynomial operator/(const polynomial &p) const { return divide(p); }
	inline polynomial operator-()const { return negative(); }

	void insert(int, int);

private:
	polynomial add(const polynomial &) const;
	polynomial minus(const polynomial &) const;
	polynomial multiply(const polynomial &)const;
	polynomial divide(const polynomial &)const;
	polynomial negative() const;

	unit *insert(unit *, unit *);
	void del(unit *);
	void append(int, int);
	unit *getunit(int, int);
	unit *newspace();
	void destory(unit *);
	bool islower(const polynomial &) const;

	unit *beg, *end;
	unit *spare;
};

	
class unit {
friend class polynomial;
friend std::ostream &operator<<(std::ostream &, const polynomial &);

private:
	unit(int base = 0, int exp = 1,
		 unit *n = NULL, unit *l = NULL);

	unit *next, *last;
	int exp;
	int coe;
};

#endif
