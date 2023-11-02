#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector<int> vec = { 4, 2, 7, 1, 9, 3 };

	// Sortiranje vektora
	std::sort(vec.begin(), vec.end());

	// Umetanje 0 ispred najmanjeg elementa
	vec.insert(vec.begin(), 0);

	// Pronalaženje najvećeg elementa
	auto maxElement = std::max_element(vec.begin(), vec.end());

	// Izračunavanje sume elemenata iza najvećeg elementa
	int sum = 0;
	bool add = false;
	for (auto it = maxElement + 1; it != vec.end(); ++it) {
		sum += *it;
		add = true;
	}

	std::cout << "Vektor nakon sortiranja i umetanja 0: ";
	for (const auto &element : vec) {
		std::cout << element << " ";
	}
	if (add) {
		std::cout << "\nSuma svih elemenata iza najvećeg elementa: " << sum << std::endl;
	}

	return 0;
}
