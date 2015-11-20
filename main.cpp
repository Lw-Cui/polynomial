#include <cstdio>
#include "polynomial.h"
using namespace std;

void test1() {
	polynomial p1, p2;

	for (int i = 0; i < 5; i++)
		p1.add(i, i + 1);
	cout << -p1;

	for (int i = 7; i > 4; i--)
		p2.add(i, i - 1);

	cout << p2 * p1;
}


void test3() {
	polynomial p1, p2;
	p1.add(10, 2);
	p1.add(1, 1);
	p2.add(5, 1);
	
	cout << p1 / p2;
}

void test4() {
	polynomial p1, p2;
	
	p1.add(-2, 2);
	p1.add(1, 1);

	p2.add(2, 1);
	p2.add(1, 0);
	
	p1 = p1 / p2;
}

int main(int args, char **agrv) { 
	test3();
	return 0;
}
