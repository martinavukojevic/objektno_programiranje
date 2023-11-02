#include <iostream>
#include <vector>
#include <algorithm>

// Funkcija koja okreće string
std::string okreniString(const std::string& str) {
    return std::string(str.rbegin(), str.rend());
}

// Funkcija koja prima stringove, sprema ih u vektor, okreće svaki string te sortira vektor po okrenutim stringovima
void obrniISortirajStringove() {
    std::vector<std::string> stringovi;
    std::string ulaz;
    int brojStringova;

    std::cout << "Unesite broj stringova: ";
    std::cin >> brojStringova;

    std::cout << "Unesite stringove:" << std::endl;
    for (int i = 0; i < brojStringova; ++i) {
        std::cin >> ulaz;
        stringovi.push_back(okreniString(ulaz));
    }

    // Sortiranje vektora
    std::sort(stringovi.begin(), stringovi.end());

    std::cout << "Sortirani stringovi:" << std::endl;
    for (const auto& str : stringovi) {
        std::cout << okreniString(str) << std::endl;
    }
}

int main() {
    obrniISortirajStringove();
    return 0;
}
