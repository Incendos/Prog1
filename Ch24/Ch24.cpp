#include "../std_lib_facilities.h"
#include "Matrix.h"

using namespace std;

int main()
{
	cout << "char: " << sizeof(char) << "\nshort: " 
	<< sizeof(short) << "\nint: " << sizeof(int) 
	<< "\nlong: " << sizeof(long) << "\nfloat: "
	<< sizeof(long) << "\ndouble: " << sizeof(double)
	<< "\nint*: " << sizeof(int*) << "\ndouble*: "
	<< sizeof(double*) << endl;

	Numeric_lib::Matrix<int> a(10), b(100);
	Numeric_lib::Matrix<double> c(10);
	Numeric_lib::Matrix<int,2> d(10,10);
	Numeric_lib::Matrix<int,3> e(10,10,10);

	cout << "a: " << sizeof(a) << "\nb: "
	<< sizeof(b) << "\nc: " << sizeof(c)
	<< "\nd: " << sizeof(d) << "\ne: "
	<< sizeof(e) << endl;

	cout << a.size() << endl << b.size() << endl
	<< c.size() << endl << d.size() << endl
	<< e.size() << endl;

	return 0;
}