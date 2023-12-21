#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
void sortirajNiz(T arr[], int velicina) {
	sort(arr, arr + velicina);
}


template <>
void sortirajNiz<char>(char arr[], int velicina) {
	sort(arr, arr + velicina, [](char a, char b) {
		return tolower(a) < tolower(b);
	});
}

int main() {

	int niz1[] = { 4, 2, 7, 1, 5 };
	char niz2[] = { 'b', 'A', 'c','z','d', 'D', 'a' };

	int velicina1 = sizeof(niz1) / sizeof(niz1[0]);
	int velicina2 = sizeof(niz2) / sizeof(niz2[0]);

	sortirajNiz(niz1, velicina1);

	cout << "Sortiran niz brojeva: ";
	for (int i = 0; i < velicina1; i++) {
		cout << niz1[i] << " ";
	}
	cout << endl;

	sortirajNiz(niz2, velicina2);

	cout << "Sortiran niz bez razlike između malih i velikih slova: ";
	for (int i = 0; i < velicina2; i++) {
		cout << niz2[i] << " ";
	}
	cout << endl;

	return 0;
}
