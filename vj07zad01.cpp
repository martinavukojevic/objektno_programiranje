#include <iostream>

class Hrana {
private:
	static int brojac;

public:
	Hrana() {
		brojac++;
	}

	~Hrana() {
		brojac--;
	}

	static int dohvatiBrojac() {
		return brojac;
	}

	static void postaviBrojac(int vrijednost) {
		brojac = vrijednost;
	}

	static void povecajBrojac() {
		brojac++;
	}

	static void smanjiBrojac() {
		brojac--;
	}

	static void ispisiBrojac() {
		std::cout << "Brojac: " << brojac << std::endl;
	}
};

int Hrana::brojac = 0;

int main() {
	Hrana hrana1;
	Hrana hrana2;
	Hrana hrana3;

	Hrana::ispisiBrojac();  

	Hrana::povecajBrojac();
	Hrana::ispisiBrojac();  

	Hrana::smanjiBrojac();
	Hrana::ispisiBrojac();  

	Hrana::postaviBrojac(10);
	Hrana::ispisiBrojac();  
	return 0;
}

