#include <cstdio>
#include "polynomial.h"
using namespace std;

void test1() {
	polynomial p1, p2;

	for (int i = 0; i < 5; i++)
		p1.insert(i, i + 1);
	p1 = p1.negative();
	p1.print();

	for (int i = 7; i > 4; i--)
		p2.insert(i, i - 1);

	//p2.print();
	//polynomial p3 = p4.add(p2);

	p2 = p2.multiply(p1);
	p2.print();
}

int main(int args, char **agrv) { 
	polynomial p1, p2;

	p1.insert(-2, 2);
	p1.insert(1, 1);

	p2.insert(2, 1);
	p2.insert(1, 0);

	p1.print();
	p2.print();

	polynomial p3 = p1.multiply(p2);
	p3.print();

	printf("p2 < p2? %d\n", p2 < p2);
	printf("p1 < p2? %d\n", p1 < p2);
	
	return 0;
}
