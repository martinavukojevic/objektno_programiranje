#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;


struct Tocka {
	double x, y;

	Tocka(double x_val, double y_val) : x(x_val), y(y_val) {}
};

void obradiTocke(const string& imeDatoteke) {
	ifstream datoteka(imeDatoteke);
	if (!datoteka.is_open()) {
		cerr << "Nemoguće otvoriti datoteku: " << imeDatoteke << endl;
		return;
	}

	istream_iterator<Tocka> it(datoteka), kraj;
	vector<Tocka> tocke(it, kraj);

	
	sort(tocke.begin(), tocke.end(),
		[](const Tocka& t1, const Tocka& t2) {
		return sqrt(t1.x * t1.x + t1.y * t1.y) < sqrt(t2.x * t2.x + t2.y * t2.y);
	});

	
	int brojTocakaUnutarKruga = count_if(tocke.begin(), tocke.end(),
		[](const Tocka& t) {
		return sqrt(t.x * t.x + t.y * t.y) < 5.0; // Promijenite radijus prema potrebi
	});


	replace_if(tocke.begin(), tocke.end(),
		[](const Tocka& t) {
		return abs(sqrt(t.x * t.x + t.y * t.y) - 3.0) < 0.001;
	},
		Tocka(10.0, 10.0));


	reverse(tocke.begin(), tocke.end());
	copy(tocke.begin(), tocke.end(), ostream_iterator<Tocka>(cout, "\n"));
}

int main() {
	
	obradiTocke("points.txt");

	return 0;
}
