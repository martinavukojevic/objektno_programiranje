#pragma once
#include <iostream>
#include <vector>
#include <string>

class VirtualPet {
private:
	std::string ime;
	std::string vrsta;
	int BodoviZaGlad;
	int BodoviZaSrecu;
	bool StatusBudnosti;

public:
	VirtualPet(std::string ime, std::string vrsta, int BodoviZaGlad = 20, int BodoviZaSrecu = 20, bool StatusBudnosti = true);
	void jede();
	void igraj();
	void spava();
	int getBodoviSreca() const;
	std::string getIme() const;
};

class Owner {
private:
	std::string ImeVlasnika;
	std::vector<VirtualPet> ljubimci;

public:
	Owner(std::string ImeVlasnika, const std::vector<VirtualPet>& ljubimci);
	void dodajLjubimca(const VirtualPet& ljubimac);
	void obaviAktivnosti();
	int ukupnaSreca() const;
	std::string getImeVlasnika() const;
	static Owner& pronadjiNajsretnijeg(std::vector<Owner>& vlasnici);
};
