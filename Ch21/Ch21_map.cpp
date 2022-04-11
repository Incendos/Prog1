#include "../std_lib_facilities.h"

using namespace std;

void read_cin(map<string, int>& i)
{
	pair<string,int> o;
	while(cin >> o.first >> o.second)
		i[o.first] = o.second;
}

template<typename f, typename s>
void print_map(const map<f, s>& i)
{
	for(const auto& o: i)
		cout << o.first << '\t' << o.second << endl;
}

int main()
{
	map<string,int> msi;

	ifstream myfile("adatok.txt");
	for(int i = 0; i < 10; i++)
	{
		double o;
		string key;
		int value;
		myfile >> key >> value >> o;
		msi[key] = value;
	}
	myfile.close();
	print_map(msi);
	
	for(int i = 0; i < 10; i++)
		msi.erase(msi.begin(), msi.end());

	read_cin(msi);
	cout << "Új map:\n";
	print_map(msi);

	cout << accumulate(msi.begin(), msi.end(), 0, [] (int i, auto o) {return i + o.second;})
	<< endl;

	map<int,string> mis;
	for(const auto& i : msi)
		mis[i.second] = i.first;
	print_map(mis);
	return 0;
}