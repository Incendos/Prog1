#include "../std_lib_facilities.h"

using namespace std;

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(e1!=f1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}
	return f2;
}

int main()
{
	int tomb[] {0,1,2,3,4,5,6,7,8,9};
	vector<int> vect {0,1,2,3,4,5,6,7,8,9};
	list<int> lista {0,1,2,3,4,5,6,7,8,9};

	int tomb2[10];
	vector<int> vect2(10);
	list<int> lista2(10);

	copy(tomb,tomb + 10,tomb2);
	vect2 = vect;
	lista2 = lista;

	for(int i = 0; i < 10; i++)
		tomb[i] += 2;
	for(auto& i : vect)
		i += 3;
	for(auto& i : lista)
		i += 5;

	my_copy(tomb, tomb + 10, vect.begin());
	my_copy(lista.begin(), lista.end(), tomb);

	if (find(vect, 3) != vect.end())
		cout << "vectorban a pos: " << find(vect, 3) - vect.begin() << endl;
	if (find(lista, 27) != lista.end())
	{
		int pos = 0;
		for(auto i = lista.begin(); find(lista, 27) != i; i++)
				pos++;
		cout << "listában a pos: " << pos << endl;
	}

	return 0;
}