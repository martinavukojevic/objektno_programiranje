#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <map>

class Karta {
public:
    int broj;
    std::string zoga;

    Karta(int broj, const std::string& zoga) : broj(broj), zoga(zoga) {}
};

class Mac {
public:
    std::vector<Karta> karte;

    Mac() {
        std::vector<std::string> zoge = {"Bastoni", "Spade", "Dinari", "Coppe"};
        for (int i = 1; i <= 10; i++) {
            for (const auto& zoga : zoge) {
                karte.push_back(Karta(i, zoga));
            }
        }
    }

    void promijesaj() {
        std::srand(static_cast<unsigned>(std::time(0)));
        std::random_shuffle(karte.begin(), karte.end());
    }

    std::vector<Karta> podijeli() {
        std::vector<Karta> ruka(karte.begin(), karte.begin() + 10);
        karte.erase(karte.begin(), karte.begin() + 10);
        return ruka;
    }
};

class Igrac {
public:
    std::string ime;
    std::vector<Karta> kombinacija;
    double bodovi;

    Igrac(const std::string& ime) : ime(ime), bodovi(0) {}

    void dodajKarte(const std::vector<Karta>& noveKarte) {
        kombinacija.insert(kombinacija.end(), noveKarte.begin(), noveKarte.end());
    }

    void izracunajBodove() {
        provjeriNapolitanu();
    }

    void provjeriNapolitanu() {
        std::map<std::string, int> bojeCount;
        std::map<int, int> brojeviCount;
        for (const auto& karta : kombinacija) {
            bojeCount[karta.zoga]++;
            brojeviCount[karta.broj]++;
        }

        for (const auto& it : bojeCount) {
            if (it.second >= 3) {
                bodovi += 3;
            }
        }

        for (const auto& it : brojeviCount) {
            if (it.second >= 3) {
                if (it.first <= 3) {
                    bodovi += 3;
                } else {
                    bodovi += 4;
                }
            }
        }
    }
};

int main() {
    int brojIgraca;
    std::cout << "Unesite broj igraca (2 ili 4): ";
    std::cin >> brojIgraca;

    std::vector<Igrac> igraci;
    for (int i = 0; i < brojIgraca; i++) {
        std::string ime;
        std::cout << "Unesite ime igraca " << i + 1 << ": ";
        std::cin >> ime;
        igraci.emplace_back(ime);
    }

    Mac mac;
    mac.promijesaj();

    for (auto& igrac : igraci) {
        auto ruka = mac.podijeli();
        igrac.dodajKarte(ruka);
        igrac.izracunajBodove();
    }

    for (const auto& igrac : igraci) {
        std::cout << "Igrac " << igrac.ime << " ima " << igrac.bodovi << " bodova iz akuzeta." << std::endl;
    }

    return 0;
}
