#include "../std_lib_facilities.h"

using namespace std;

int main()
{
	vector<double> vd(16);
	ifstream myfile("float.txt");
	for(auto& i : vd)
		myfile >> i;
	myfile.close();

	for(const auto& i : vd)
		cout << i << endl;

	cout << endl;
	vector<int> vi(16);
	copy(vd.begin(), vd.end(), vi.begin());
	for(int i = 0; i < 16; i++)
		cout << vd[i] << " " << vi[i] << endl;

	cout << "\nsum of vd: " << accumulate(vd.begin(), vd.end(), 0.0)
	<< endl;

	cout << "diff: " << accumulate(vd.begin(), vd.end(), 0.0) - accumulate(vi.begin(), vi.end(), 0)
	<< endl;

	cout << "\nreversed:\n";
	reverse(vd.begin(), vd.end());
	for(int i = 0; i < 16; i++)
		cout << vd[i] << endl;

	double avg = accumulate(vd.begin(), vd.end(), 0.0)/16;
	cout << "\navg: " << avg << endl;

	vector<double> vd2(16);
	copy_if(vd.begin(), vd.end(), vd2.begin(), [&] (double i) {return i < avg;});
	
	sort(vd2);
	for(const auto& i : vd2)
		cout << i << endl;

	return 0;
}