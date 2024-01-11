#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std;

void promijeniRijeci(const string& imeDatoteke) {
	ifstream datoteka(imeDatoteke);
	if (!datoteka.is_open()) {
		cerr << "Nemoguće otvoriti datoteku: " << imeDatoteke << endl;
		return;
	}

	istream_iterator<string> it(datoteka), kraj;
	vector<string> rijeci(it, kraj);

	vector<int> pozicije;
	auto itPronadi = find(rijeci.begin(), rijeci.end(), "odredena_rijec");
	while (itPronadi != rijeci.end()) {
		pozicije.push_back(distance(rijeci.begin(), itPronadi));
		itPronadi = find(next(itPronadi), rijeci.end(), "odredena_rijec");
	}

	
	rijeci.erase(remove_if(rijeci.begin(), rijeci.end(),
		[](const string& s) { return s.find("odredeni_podstring") != string::npos; }),
		rijeci.end());

	
	transform(rijeci.begin(), rijeci.end(), rijeci.begin(),
		[](string s) {
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		return s;
	});

	
	copy(rijeci.begin(), rijeci.end(), ostream_iterator<string>(cout, " "));
	cout << endl;
}

int main() {
	
	promijeniRijeci("words.txt");

	return 0;
}

