#include <iostream>
#include <vector>
#include <stdexcept>
#include<string>
using namespace std;

class Neprijatelj {
public:
	Neprijatelj(const string& ime, int zdravlje, int steta) : ime(ime), zdravlje(zdravlje), steta(steta) {
		if (zdravlje < 0 || steta < 0) {
			throw invalid_argument("Zdravlje i steta moraju biti nenegativni brojevi.");
		}
	}

	virtual void napadni() = 0;
	virtual void prikaziInfo() const = 0;

protected:
	string ime;
	int zdravlje;
	int steta;
};

class Vlasnik : public Neprijatelj {
public:
	Vlasnik(const string& ime, int zdravlje, int steta, const string& oruzje)
		: Neprijatelj(ime, zdravlje, steta), oruzje(oruzje) {
		if (oruzje.empty()) {
			throw invalid_argument("Oruzje ne moze biti prazno.");
		}
	}

	void napadni() {
		cout << "Vlasnik napada s -> " << oruzje << " -> nanoseci " << steta << " stete.\n";
	}

	void prikaziInfo() const {
		cout << "Vlasnik: " << ime << ", Zdravlje: " << zdravlje << ", Oruzje: " << oruzje << endl;
	}

private:
	string oruzje;
};

class Zvijer : public Neprijatelj {
public:
	Zvijer(const string& ime, int zdravlje, int steta, const string& sposobnost)
		: Neprijatelj(ime, zdravlje, steta), sposobnost(sposobnost) {
		if (sposobnost.empty()) {
			throw invalid_argument("Sposobnost ne moze biti prazna.");
		}
	}

	void napadni() {
		cout << "Zvijer napada s -> " << sposobnost << " -> nanoseci " << steta << " stete.\n";
	}

	void prikaziInfo() const {
		cout << "Zvijer: " << ime << ", Zdravlje: " << zdravlje << ", Sposobnost: " << sposobnost << endl;
	}

private:
	string sposobnost;
};

int main() {
	vector<unique_ptr<Neprijatelj>> neprijatelji;

	neprijatelji.push_back(make_unique<Vlasnik>("Mate", 100, 20, "Mac"));
	neprijatelji.push_back(make_unique<Zvijer>("Ante", 80, 15, "Puska"));

	for (const auto& neprijatelj : neprijatelji) {
		neprijatelj->napadni();
		neprijatelj->prikaziInfo();
	}

	return 0;
}
