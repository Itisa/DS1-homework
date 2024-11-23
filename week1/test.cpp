#include "polynomial.h"


int main()
{
	poly p;
	p.insert(3,2);
	p.insert(2, 1);
	p.insert(1, 0);
	p.insert(4, 3);
	double x = 2;
	cout << "多项式结果为" << p.calc(x) << endl;
}