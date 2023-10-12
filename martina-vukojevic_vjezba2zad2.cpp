
#include <iostream>

int& incrementElement(int arr[], int index) {
	return arr[index];
}

int main() {
	int myArray[] = { 1, 2, 3, 4, 5 };
	int indexToIncrement = 2;

	std::cout << "Prije povećanja: myArray[" << indexToIncrement << "] = " << myArray[indexToIncrement] << std::endl;

	incrementElement(myArray, indexToIncrement)++;

	std::cout << "Nakon povećanja: myArray[" << indexToIncrement << "] = " << myArray[indexToIncrement] << std::endl;

	return 0;
}

