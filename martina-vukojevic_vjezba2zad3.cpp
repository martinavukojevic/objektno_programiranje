#include <iostream>

struct Vektor {
	int* niz; // niz int elemenata
	int logička_veličina; // logička veličina niza
	int fizička_veličina; // fizička veličina niza
	int inicijalna_veličina; // inicijalna fizička veličina

	void vector_new(int inicijalna_veličina) {
		niz = new int[inicijalna_veličina];
		logička_veličina = 0;
		fizička_veličina = inicijalna_veličina;
		this->inicijalna_veličina = inicijalna_veličina;
	}

	void vector_delete() {
		delete[] niz;
	}

	void vector_push_back(int vrijednost) {
		if (logička_veličina == fizička_veličina) {
			int* temp = new int[2 * fizička_veličina];
			for (int i = 0; i < logička_veličina; i++) {
				temp[i] = niz[i];
			}
			delete[] niz;
			niz = temp;
			fizička_veličina *= 2;
		}
		niz[logička_veličina] = vrijednost;
		logička_veličina++;
	}

	void vector_pop_back() {
		if (logička_veličina > 0) {
			logička_veličina--;
			if (logička_veličina <= fizička_veličina / 4 && fizička_veličina > inicijalna_veličina) {
				int* temp = new int[fizička_veličina / 2];
				for (int i = 0; i < logička_veličina; i++) {
					temp[i] = niz[i];
				}
				delete[] niz;
				niz = temp;
				fizička_veličina /= 2;
			}
		}
		else {
			std::cout << "Greška prilikom uklanjanja iz vektora: Pokušaj uklanjanja iz praznog vektora." << std::endl;
		}
	}

	int vector_front() {
		if (logička_veličina > 0) {
			return niz[0];
		}
		else {
			std::cout << "Vektor je prazan." << std::endl;
			return -1;
		}
	}

	int vector_back() {
		if (logička_veličina > 0) {
			return niz[logička_veličina - 1];
		}
		else {
			std::cout << "Vektor je prazan." << std::endl;
			return -1;
		}
	}

	int vector_size() {
		return logička_veličina;
	}
};

int main() {
	Vektor v;
	v.vector_new(2);

	v.vector_push_back(5);
	v.vector_push_back(10);
	v.vector_push_back(15);

	std::cout << "Prvi element: " << v.vector_front() << std::endl;
	std::cout << "Zadnji element: " << v.vector_back() << std::endl;
	std::cout << "Veličina: " << v.vector_size() << std::endl;

	v.vector_pop_back();

	std::cout << "Prvi element nakon uklanjanja: " << v.vector_front() << std::endl;
	std::cout << "Zadnji element nakon uklanjanja: " << v.vector_back() << std::endl;
	std::cout << "Veličina nakon uklanjanja: " << v.vector_size() << std::endl;

	v.vector_delete();

	return 0;
}