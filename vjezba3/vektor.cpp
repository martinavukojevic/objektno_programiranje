#include "vektor.hpp"
#include<iostream>

void unosVektora(std::vektor<int>&vektor, int brojElemenata) {
	vektor.clear();
	int broj;
	for (int i = 0; i < BrojElemenata; i++) {
		std::cin >> broj;
		vector.push_back(broj);
	}
}
void unosVektora(std::vector<int>&vektor, int donjaGranica, int gornjaGranica) {
	vektor.clear;
	int broj;
	while (true) {
		std::cin >> broj;
		if (broj<donjaGranica || broj>gornjaGranica) {
			break;
		}
		vektor.push_back(broj);
	}
}
void ispisVektora(std::vektor<int>&vektor) {
	for (auto elem : vektor) {
		std::cout << elem << " ";

	}
	std::cout << std::endl;
}