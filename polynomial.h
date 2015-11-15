#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
//TO DO: COPY CONSTRUCTOR

class unit;

class polynomial {
public:
	polynomial();
	~polynomial();

	polynomial(const polynomial &);
	polynomial &operator=(const polynomial &);
	bool operator<(const polynomial &);

	void insert(int, int);
	void print() const;

	polynomial add(const polynomial &) const;
	polynomial minus(const polynomial &) const;
	polynomial multiply(const polynomial &)const;
	polynomial divide(const polynomial &)const;
	polynomial negative() const;
private:
	unit *insert(unit *, unit *);
	void del(unit *);
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
