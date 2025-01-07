#include <iostream>
#include <string>

class Food {
private:
    static int counter;

public:
    Food() {
        counter++;
    }

    static int getCounter() {
        return counter;
    }
};

int Food::counter = 0;

class VirtualPet {
private:
    std::string name;
    std::string type;
    int points;

public:
    VirtualPet(std::string petName, std::string petType, int petPoints)
        : name(petName), type(petType), points(petPoints) {}

    bool operator==(const VirtualPet& other) const {
        return name == other.name && type == other.type && points == other.points;
    }

    VirtualPet& operator++() {
        points -= 1;  // Pretpostavka: svaka porcija smanjuje određeni broj bodova gladnosti
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const VirtualPet& pet) {
        os << "Name: " << pet.name << ", Type: " << pet.type << ", Points: " << pet.points;
        return os;
    }
};

int main() {
    // Testiranje klase Food
    Food food1;
    std::cout << "Counter: " << Food::getCounter() << std::endl;

    // Testiranje klase VirtualPet
    VirtualPet pet1("Buddy", "Dog", 100);
    VirtualPet pet2("Mittens", "Cat", 80);

    std::cout << "Pet1: " << pet1 << std::endl;
    std::cout << "Pet2: " << pet2 << std::endl;

    if (pet1 == pet2) {
        std::cout << "Pets are equal." << std::endl;
    } else {
        std::cout << "Pets are not equal." << std::endl;
    }

    ++pet1;
    std::cout << "Pet1 after eating: " << pet1 << std::endl;

    return 0;
}
