#include "../std_lib_facilities.h"

using namespace std;

struct B1
{
	virtual void vf()
	{
		cout << "B1::vf()" << endl;
	}

	void f()
	{
		cout << "B1::f()" << endl;
	}
};

class D1 : public B1
{
public:
	void vf() override
	{
		cout << "D1::vf()" << endl;
	}
};

int main()
{
	B1 obj1;
	obj1.vf();
	obj1.f();

	cout << endl;

	D1 obj2;
	obj2.vf();
	obj2.f();

	cout << endl;

	B1& ref_obj1 = obj2;
	ref_obj1.vf();
	ref_obj1.f();
	return 0;
}