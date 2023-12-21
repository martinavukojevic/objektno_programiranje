#include <iostream>
#include <unordered_set>
using namespace std;

template <typename T>
class Skup {
private:
	unordered_set<T> elementi;

public:
	void dodaj(const T& element) {
		elementi.insert(element);
	}

	void ukloni(const T& element) {
		elementi.erase(element);
	}

	bool sadrzi(const T& element) const {
		return elementi.find(element) != elementi.end();
	}
};

int main() {

	Skup<int> skupCijelihBrojeva;

	skupCijelihBrojeva.dodaj(5);
	skupCijelihBrojeva.dodaj(10);
	skupCijelihBrojeva.dodaj(15);

	cout << "Sadrži li skup broj 10? ";
	if (skupCijelihBrojeva.sadrzi(10)) {
		cout << "Da";
	}
	else {
		cout << "Ne";
	}
	cout << endl;


	skupCijelihBrojeva.ukloni(10);

	cout << "Sadrži li skup broj 10 nakon uklanjanja? " << (skupCijelihBrojeva.sadrzi(10) ? "Da" : "Ne") << endl;

	return 0;
}
