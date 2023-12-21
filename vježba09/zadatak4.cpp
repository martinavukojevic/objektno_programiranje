#include <iostream>
#include <cmath>
using namespace std;

template <typename T>
class point {
private:
	T x, y;

public:
	point(T x_val, T y_val) : x(x_val), y(y_val) {}

	friend double operator-(const point& p1, const point& p2) {
		return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
	}

	friend ostream& operator<<(ostream& os, const point& p) {
		os << "(" << p.x << ", " << p.y << ")";
		return os;
	}
};

int main() {
	point<int> p1(2, 3), p2(3, 4);
	cout << "Udaljenost tacaka " << p1 << " i " << p2 << " je " << p1 - p2 << endl;

	return 0;
}
