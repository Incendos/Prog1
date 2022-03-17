#include "std_lib_facilities.h"

using namespace std;

const string invalidch {";:\"'[]*&^%$#@!"};

struct Person
{
private:
	string fn;
	string sn;
	int a;
public:
	Person(string ffn, string ssn, int aa):
	fn{ffn}, sn{ssn}, a{aa}
	{
		if (a < 0 || a > 150)
			error("Invalid age in constructor\n");
		for(auto invalid : invalidch)
			for(auto ch: fn)
				if (invalid == ch)
					error("Invalid firstname in constructor\n");
		for(auto invalid : invalidch)
			for(auto ch: sn)
				if (invalid == ch)
					error("Invalid secondname in constructor\n");
	}

	Person():
	fn{"Kovács"}, sn{"János"}, a{18} {}

	string fname() const {return fn;}
	string sname() const {return sn;}
	int age() const {return a;}
};

ostream& operator<<(ostream& s, Person& p)
{
	return s << p.fname() << " " << p.sname() << " "
	<< p.age();
}

istream& operator>>(istream& s, Person& p)
{
	string fn = "", sn = "";
	int a = 0;
	s >> fn;
	if(!s)
		error("input error to fn\n");
	s >> sn;
	if(!s)
		error("input error to sn\n");
	s >> a;
	if(!s)
		error("input error to a\n");
	p = Person {fn, sn, a};
	return s;
}

int main()
{
	try {

	Person smb {"Lakatos","Goofy",63};
	cout << smb << endl;
	
	vector<Person> people(10); //def konstruktor ehhez kellett csak
	
	for(int i = 0; i < 10; i++)
		cin >> people[i];
	
	cout << "Lista:\n";
	for(auto i : people)
		cout << i << endl;

	return 0;
	}

	catch(exception& e)
	{
		cerr << "error: " << e.what();
		return 1;
	}

	catch(...)
	{
		cerr << "error";
		return 2;
	}
}