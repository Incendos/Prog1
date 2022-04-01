#include "../std_lib_facilities.h"

using namespace std;

template<typename T>
struct S
{
	S(T vv): val(vv) {}
	T& get();
	const T& get() const;
	//void set(T vv);
	S<T>& operator=(const T&);
private:
	T val;
};

template<typename T> T& S<T>::get()
{
	return val;
}

template<typename T> const T& S<T>::get() const
{
	return val;
}

template<typename T> S<T>& S<T>::operator=(const T& vv)
{
	val = vv;
	return *this;
}

template<typename T> ostream& operator<<(ostream& os, const vector<T>& vv)
{
	os << '{';
	for(int i = 0; i < vv.size() - 1; i++)
		os << vv[i] << ',';
	os << vv[vv.size() - 1] << '}';
	return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& vv)
{
	char cc = 0;
	is >> cc;
	if (cc != '{') error("expected '{' first");

	for(int i = 0; i < vv.size() - 1; i++)
		{
			is >> vv[i] >> cc;
			if(cc != ',') error("expected ',' between values");
		}

	is >> vv[vv.size() - 1] >> cc;
	if(cc != '}') error("expected '}' at end");
		
	return is;
}

template<typename T> void read_val(T& v)
{
	cin >> v;
}

/*
template<typename T> void S<T>::set(T vv)
{
	val = vv;
}
*/

int main()
{
	try {
	S<int> ii {11};
	S<char> cc {'w'};
	S<double> dd {2.5};
	S<string> ss {"valami"};
	S<vector<int>> vv {vector<int>{10,11,22}};

	read_val(ii.get());
	read_val(cc.get());
	read_val(dd.get());
	read_val(ss.get());
	read_val(vv.get());

	cout << ii.get() << endl;
	cout << cc.get() << endl;
	cout << dd.get() << endl;
	cout << ss.get() << endl;
	cout << vv.get() << endl;

	return 0;
	}

	catch(exception& e)
	{
		cerr << e.what() << endl;
		return 1;
	}
	catch(...)
	{
		cerr << "error\n";
		return 2;
	}
}