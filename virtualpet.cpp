#include "virtualpet.hpp"
#include <algorithm>
#include <ctime>

VirtualPet::VirtualPet(std::string ime, std::string vrsta, int BodoviZaGlad, int BodoviZaSrecu, bool StatusBudnosti)
	: ime(ime), vrsta(vrsta), BodoviZaGlad(BodoviZaGlad), BodoviZaSrecu(BodoviZaSrecu), StatusBudnosti(StatusBudnosti) {}

void VirtualPet::jede() {
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

void VirtualPet::igraj() {
	BodoviZaSrecu += 2;
	BodoviZaGlad += 2;
	std::cout << ime << " se igra." << std::endl;
}

void VirtualPet::spava() {
	BodoviZaGlad += 2;
	BodoviZaSrecu += 2;
	std::cout << ime << " spava." << std::endl;
}

int VirtualPet::getBodoviSreca() const {
	return BodoviZaSrecu;
}

std::string VirtualPet::getIme() const {
	return ime;
}

Owner::Owner(std::string ImeVlasnika, const std::vector<VirtualPet>& ljubimci)
	: ImeVlasnika(ImeVlasnika), ljubimci(ljubimci) {}

void Owner::dodajLjubimca(const VirtualPet& ljubimac) {
	ljubimci.push_back(ljubimac);
}

void Owner::obaviAktivnosti() {
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

int Owner::ukupnaSreca() const {
	int ukupnaSreca = 0;
	for (const VirtualPet& ljubimac : ljubimci) {
		ukupnaSreca += ljubimac.getBodoviSreca();
	}
	return ukupnaSreca;
}

std::string Owner::getImeVlasnika() const {
	return ImeVlasnika;
}

Owner& Owner::pronadjiNajsretnijeg(std::vector<Owner>& vlasnici) {
	auto najVlasnik = std::max_element(vlasnici.begin(), vlasnici.end(), [](const auto& a, const auto& b) {
		return a.ukupnaSreca() < b.ukupnaSreca();
	});
	return *najVlasnik;
}

int main() {
	srand(time(0));

	VirtualPet pet1("Rex", "Pas");
	VirtualPet pet2("Mate", "Macka");

	Owner owner1("Martina", { pet1, pet2 });
	Owner owner2 = owner1;

	owner1.obaviAktivnosti();
	owner1.obaviAktivnosti();
	owner2.obaviAktivnosti();

	std::cout << "Sreca owner1: " << owner1.ukupnaSreca() << std::endl;
	std::cout << "Sreca owner2: " << owner2.ukupnaSreca() << std::endl;

	std::vector<Owner> vlasnici = { owner1, owner2 };
	Owner& najsretnijiVlasnik = Owner::pronadjiNajsretnijeg(vlasnici);
	std::cout << "Najsretniji vlasnik: " << najsretnijiVlasnik.getImeVlasnika() << std::endl;

	return 0;
}
