#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

class VirtualPet {
private:
	string ime;
	string vrsta;
	int BodoviZaGlad;
	int BodoviZaSrecu;
	bool StatusBudnosti;

public:

	VirtualPet(string ime, string vrsta, int BodoviZaGlad = 20, int BodoviZaSrecu = 20, bool StatusBudnosti = true) {
    this->ime = ime;
    this->vrsta = vrsta;
    this->BodoviZaGlad = BodoviZaGlad;
    this->BodoviZaSrecu = BodoviZaSrecu;
    this->StatusBudnosti = StatusBudnosti;

}

		void jede() {
			if (StatusBudnosti == true) {
				BodoviZaSrecu += 2;
				BodoviZaGlad -= 2;
				std::cout << ime << " je pojeo hranu." << std::endl;
				for (int i = 0; i < 5; i++) {
					StatusBudnosti = false;
					BodoviZaGlad += 2;
				}
			}
		}

		void igraj() {
			BodoviZaSrecu += 2;
			BodoviZaGlad += 2;
			std::cout << ime << " se igra." << std::endl;
		}

		void spava() {
			BodoviZaGlad += 2;
			BodoviZaSrecu += 2;
			std::cout << ime << " spava." << std::endl;
		}


	int getBodoviSreca() const {
		return BodoviZaSrecu;
	}

	string getIme() const {
		return ime;
	}
};

class Owner {
private:
	string ImeVlasnika;
	vector<VirtualPet> ljubimci;

public:
	Owner(string ImeVlasnika, const vector<VirtualPet>& ljubimci)
		: ImeVlasnika(ImeVlasnika), ljubimci(ljubimci) {}

	void dodajLjubimca(const VirtualPet& ljubimac) {
		ljubimci.push_back(ljubimac);
	}

	void obaviAktivnosti() {
		for (VirtualPet& ljubimac : ljubimci) {
			int brojHranjenja = rand() % 10;
			int brojIgranja = rand() % 10;

			for (int i = 0; i < brojHranjenja; i++) {
				ljubimac.jede();
			}
			for (int i = 0; i < brojIgranja; i++) {
				ljubimac.igraj();
			}
		}
	}

	int ukupnaSreca() const {
		int ukupnaSreca = 0;
		for (const VirtualPet& ljubimac : ljubimci) {
			ukupnaSreca += ljubimac.getBodoviSreca();
		}
		return ukupnaSreca;
	}

	string getImeVlasnika() const {
		return ImeVlasnika;
	}

	static Owner& pronadjiNajsretnijeg(vector<Owner>& vlasnici) {
		auto najVlasnik = max_element(vlasnici.begin(), vlasnici.end(), [](const auto& a, const auto& b) {
			return a.ukupnaSreca() < b.ukupnaSreca();
		});
		return *najVlasnik;
	}
};

int main() {
    srand(time(0));


    VirtualPet pet1("Rex", "Pas");
    VirtualPet pet2("Mate", "Macka");

    Owner owner1("Martina", { pet1, pet2 });

    Owner owner2 = owner1;

    owner1.obaviAktivnosti();
    owner1.obaviAktivnosti();
    owner2.obaviAktivnosti();

    cout << "Sreca owner1: " << owner1.ukupnaSreca() << endl;
    cout << "Sreca owner2: " << owner2.ukupnaSreca() << endl;

    vector<Owner> vlasnici = {owner1, owner2};
    Owner& najsretnijiVlasnik = Owner::pronadjiNajsretnijeg(vlasnici);
    cout << "Najsretniji vlasnik: " << najsretnijiVlasnik.getImeVlasnika() << endl;

    return 0;
}
