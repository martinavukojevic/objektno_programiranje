#include <iostream>
#include <string>
using namespace std;

template <typename T>
T min(const T& a, const T& b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	
	int br1 = 5, br2 = 3;
	cout << "Min od " << br1 << " i " << br2 << " je: " << min(br1, br2) << endl;


	string str1 = "Hello", str2 = "World";
	cout << "Min od \"" << str1 << "\" i \"" << str2 << "\" je: \"" << min(str1, str2) << "\"" << endl;


	return 0;
}
