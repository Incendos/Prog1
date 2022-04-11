#include "../std_lib_facilities.h"

using namespace std;

struct Item
{
	string name;
	int iid;
	double value;
};

void print_vect(const vector<Item>& o)
{
	for(const auto& i : o)
		cout << i.name << '\t' << i.iid << '\t' << i.value << endl;
}

int main()
{
	vector<Item> vi(10);

	ifstream myfile("adatok.txt");
	for(auto& i : vi)
		myfile >> i.name >> i.iid >> i.value;
	myfile.close();
	
	cout << "rendezetlen:\n";
	print_vect(vi);

	cout <<"\nnév szerint:\n";
	sort(vi.begin(),vi.end(),[] (Item i, Item o) {return i.name<o.name;});
	print_vect(vi);
	
	cout <<"\niid szerint:\n";
	sort(vi.begin(),vi.end(),[] (Item i, Item o) {return i.iid<o.iid;});
	print_vect(vi);

	cout <<"\nérték szerint desc:\n";
	sort(vi.begin(),vi.end(),[] (Item i, Item o) {return i.value>o.value;});
	print_vect(vi);

	cout <<"\nbeszúrás után:\n";
	vi.insert(vi.begin(), Item{"horse shoe",99,12.34});
	vi.insert(vi.begin(), Item{"Canon S400",9988,499.95});
	print_vect(vi);

	cout << "\n1. törlés után:\n";
	vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.name == "Yoghurt";}));
	vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.name == "Pizza";}));
	print_vect(vi);

	cout << "\n2. törlés után:\n";
	vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.iid == 16;}));
	vi.erase(find_if(vi.begin(), vi.end(), [] (Item i) {return i.iid == 91;}));
	print_vect(vi);

	return 0;
}