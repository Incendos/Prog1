#include "../std_lib_facilities.h"
#include "Matrix.h"
#include <complex>

using namespace std;

int main()
{
	for (int i; cin>>i;)
	{
		i < 0 ? cout << "No square root\n" : cout << sqrt(i) << endl;
	}

	cin.clear();
	cin.ignore();

	cout << "Mátrix elemei beírva:\n";
	Numeric_lib::Matrix<double> mat(10);
	double o;
	for(int i = 0; i < 10; i++)
	{
		cin >> mat[i];
	}

	cout << "Mátrix elemei kiírva:\n";
	for(int i = 0; i < 10; i++)
		cout << mat[i] << endl;

	int n,m;
	cin >> n >> m;
	cout << "multiplication table:\n";
	Numeric_lib::Matrix<int,2> multi_m(n,m);

	for(int i = 0; i < n; i++)
	{
		for(int o = 0; o < m; o++)
		{
			multi_m(i,o) = i*o;
			cout << multi_m(i,o) << "\t";
		}
		cout << endl;
	}


	Numeric_lib::Matrix<complex<double>,1> km(10);
	for(int i = 0; i < 10; i++)
		cin >> km[i];
	complex<double> szum = 0;
	for(int i = 0 ; i < 10; i++)
		szum += km[i];
	cout << "Sum of complexs: " << szum << endl;

	Numeric_lib::Matrix<int,2> matr(2,3);
	for(int i = 0; i < 2; i++)
		for(int o = 0; o < 3; o++)
			cin >> matr[i][o];

	for(int i = 0; i < 2; i++)
	{
		for(int o = 0; o < 3; o++)
			cout << matr[i][o] << "\t";
		cout << endl;
	}
	return 0;
}