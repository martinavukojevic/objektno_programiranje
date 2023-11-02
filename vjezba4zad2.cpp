#include <iostream>
#include <string>

std::string ispraviRecenicu(const std::string& recenica) {
    std::string ispravljenaRecenica;
    bool prijeInterpunkcije = true;

    for (char znak : recenica) {
        if (znak == ' ' || znak == '\t' || znak == '\n') {
            if (prijeInterpunkcije) {
                continue;
            } else {
                ispravljenaRecenica += ' ';
                prijeInterpunkcije = true;
            }
        } else if (znak == '.' || znak == ',' || znak == '!' || znak == '?') {
            if (ispravljenaRecenica.length() > 0 && ispravljenaRecenica.back() == ' ') {
                ispravljenaRecenica.pop_back();
            }
            ispravljenaRecenica += znak;
            ispravljenaRecenica += ' ';
            prijeInterpunkcije = true;
        } else {
            ispravljenaRecenica += znak;
            prijeInterpunkcije = false;
        }
    }

    // Uklanjanje praznina na kraju, ako postoje
    while (!ispravljenaRecenica.empty() && (ispravljenaRecenica.back() == ' ' || ispravljenaRecenica.back() == '\t' || ispravljenaRecenica.back() == '\n')) {
        ispravljenaRecenica.pop_back();
    }

    return ispravljenaRecenica;
}

int main() {
    std::string recenica = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .";
    std::string ispravljenaRecenica = ispraviRecenicu(recenica);
    std::cout << "Ispravljena rečenica: " << ispravljenaRecenica << std::endl;
    return 0;
}
