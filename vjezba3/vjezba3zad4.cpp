#include <iostream>
#include <vector>

void ukloniElement(std::vector<int> &vektor, int element) {
	for (int i = 0; i < vektor.size(); i++) {
		if (vektor[i] == element) {
			vektor[i] = vektor.back(); // Zamijeni trenutni element s posljednjim
			vektor.pop_back(); // Ukloni zadnji element
			return;
		}
	}
	std::cout << "Element nije pronađen u vektoru." << std::endl;
}

int main() {
	std::vector<int> vektor = { 4, 2, 7, 1, 9, 3 };
	int element = 7;

	std::cout << "Vektor prije uklanjanja: ";
	for (const auto &elem : vektor) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	ukloniElement(vektor, element);

	std::cout << "Vektor nakon uklanjanja: ";
	for (const auto &elem : vektor) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	return 0;
}
