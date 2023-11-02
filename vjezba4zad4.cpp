#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

bool isSamoglasnik(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

std::string pigLatinPrevod(const std::string& recenica) {
    std::stringstream ss(recenica);
    std::string rijec;
    std::string prevod;
    while (ss >> rijec) {
        if (isSamoglasnik(rijec[0])) {
            prevod += rijec + "hay ";
        } else {
            int i = 0;
            while (i < rijec.length() && !isSamoglasnik(rijec[i])) {
                i++;
            }
            prevod += rijec.substr(i) + rijec.substr(0, i) + "ay ";
        }
    }
    // Uklanjanje zadnjeg razmaka
    prevod.pop_back();
    return prevod;
}

int main() {
    std::vector<std::string> recenice = {"What time is it?", "I am learning C++", "Programming is fun"};
    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % recenice.size();
    std::string izabranaRecenica = recenice[index];
    std::string pigLatinRecenica = pigLatinPrevod(izabranaRecenica);
    std::cout << "Originalna rečenica: " << izabranaRecenica << std::endl;
    std::cout << "Pig Latin prevod: " << pigLatinRecenica << std::endl;
    return 0;
}
