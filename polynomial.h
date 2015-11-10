#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

class unit;

class polynomial {
public:
	polynomial();
	~polynomial();

	void insert(int, int);
	void print() const;

	polynomial add(const polynomial &) const;
private:
	unit *insert(unit *, unit *);
	void append(int, int);
	unit *getunit(int, int);
	unit *newspace();
	void destory(unit *);

	unit *beg, *end;
	unit *spare;
};

class unit {
friend class polynomial;

private:
	unit(int base = 0, int exp = 1,
		 unit *n = NULL, unit *l = NULL);

	unit *next, *last;
	int exp;
	int coe;
};

#endif