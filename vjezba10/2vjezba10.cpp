#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

// Struktura koja predstavlja točku
struct Tocka {
	double x, y;

	Tocka(double x_val, double y_val) : x(x_val), y(y_val) {}
};

void obradiTocke(const string& imeDatoteke) {
	// 1. Napuni vektor točaka koristeći istream iterator.
	ifstream datoteka(imeDatoteke);
	if (!datoteka.is_open()) {
		cerr << "Nemoguće otvoriti datoteku: " << imeDatoteke << endl;
		return;
	}

	istream_iterator<Tocka> it(datoteka), kraj;
	vector<Tocka> tocke(it, kraj);

	// 2. Sortiraj točke prema udaljenosti od ishodišta koristeći sort.
	sort(tocke.begin(), tocke.end(),
		[](const Tocka& t1, const Tocka& t2) {
		return sqrt(t1.x * t1.x + t1.y * t1.y) < sqrt(t2.x * t2.x + t2.y * t2.y);
	});

	// 3. Prebroji koliko točaka leži unutar određenog kruga s centrom u ishodištu koristeći count if.
	int brojTocakaUnutarKruga = count_if(tocke.begin(), tocke.end(),
		[](const Tocka& t) {
		return sqrt(t.x * t.x + t.y * t.y) < 5.0; // Promijenite radijus prema potrebi
	});

	// 4. Zamijeni sve točke koje su točno na određenoj udaljenosti od ishodišta s novom točkom koristeći replace if.
	replace_if(tocke.begin(), tocke.end(),
		[](const Tocka& t) {
		return abs(sqrt(t.x * t.x + t.y * t.y) - 3.0) < 0.001; // Promijenite udaljenost prema potrebi
	},
		Tocka(10.0, 10.0)); // Novi podaci za zamjenu

// 5. Ispiši točke iz vektora u obrnutom redoslijedu koristeći reverse i copy.
	reverse(tocke.begin(), tocke.end());
	copy(tocke.begin(), tocke.end(), ostream_iterator<Tocka>(cout, "\n"));
}

int main() {
	// Poziv funkcije za točke
	obradiTocke("points.txt");

	return 0;
}
