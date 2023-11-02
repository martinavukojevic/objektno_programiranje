#include <iostream>
#include <string>

int countSubstring(const std::string& str, const std::string& subStr) {
    if (subStr.length() == 0) return 0;
    int count = 0;
    size_t pos = 0;
    while ((pos = str.find(subStr, pos)) != std::string::npos) {
        ++count;
        pos += subStr.length();
    }
    return count;
}

int main() {
    std::string str = "abrakadabra";
    std::string subStr = "abra";
    int occurrences = countSubstring(str, subStr);
    std::cout << "Broj pojavljivanja podstringa '" << subStr << "' u stringu '" << str << "' je: " << occurrences << std::endl;
    return 0;
}
