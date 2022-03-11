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
	virtual void pvf() = 0;
};

class D1 : public B1
{
public:
	void vf() override
	{
		cout << "D1::vf()" << endl;
	}
	void f()
	{
		cout << "D1::f()" << endl;
	}
	void pvf()	override
	{
		cout << "D1::pvf()" << endl;
	}
};

class D2 : public D1
{
public:
	void pvf()	override
	{
		cout << "D2::pvf()" << endl;
	}
};

class B2
{
public:
	virtual void pvf() = 0;
};

class D21 : public B2
{
	string a = "pls";
	void pvf() override
	{
		cout << a << endl;
	}	
};

class D22 : public B2
{
	int a = 123;
	void pvf()
	{
		cout << a << endl;
	}
};

void f(B2& obj)
{
	obj.pvf();
}


int main()
{

	/*
	B1 obj1;
	obj1.vf();
	obj1.f();
	*/

	cout << endl;

	D1 obj2;
	obj2.vf();
	obj2.f();

	cout << endl;

	B1& ref_obj1 = obj2;
	ref_obj1.vf();
	ref_obj1.f();

	cout << endl;

	D2 obj3;
	obj3.vf();
	obj3.f();
	obj3.pvf();

	D21 obj4;
	D22 obj5;

	f(obj4);
	f(obj5);
	return 0;
}