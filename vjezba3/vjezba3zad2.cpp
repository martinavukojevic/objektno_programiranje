#include <iostream>
#include <vector>
#include <algorithm>

// Funkcija koja vraća vektor koji se sastoji od elemenata prvog vektora koji nisu u drugom vektoru
std::vector<int> razlikaVektora(const std::vector<int>& prvi, const std::vector<int>& drugi) {
	std::vector<int> rezultat;
	for (const auto& element : prvi) {
		if (std::find(drugi.begin(), drugi.end(), element) == drugi.end()) {
			rezultat.push_back(element);
		}
	}
	return rezultat;
}

int main() {
	std::vector<int> prviVektor = { 1, 2, 3, 4, 5 };
	std::vector<int> drugiVektor = { 3, 4, 6 };

	std::vector<int> rezultatniVektor = razlikaVektora(prviVektor, drugiVektor);

	std::cout << "Rezultatni vektor: ";
	for (const auto& element : rezultatniVektor) {
		std::cout << element << " ";
	}
	std::cout << std::endl;

	return 0;
}
