#include <iostream>

struct Matrica {
	int redovi;
	int stupci;
	float** elementi;

	void stvori_matricu(int m, int n) {
		redovi = m;
		stupci = n;
		elementi = new float*[redovi];
		for (int i = 0; i < redovi; i++) {
			elementi[i] = new float[stupci];
		}
	}

	void unesi_matricu() {
		std::cout << "Unesite elemente matrice: " << std::endl;
		for (int i = 0; i < redovi; i++) {
			for (int j = 0; j < stupci; j++) {
				std::cin >> elementi[i][j];
			}
		}
	}

	void generiraj_matricu(float a, float b) {
		for (int i = 0; i < redovi; i++) {
			for (int j = 0; j < stupci; j++) {
				elementi[i][j] = a + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (b - a)));
			}
		}
	}

	void zbroji_matrice(Matrica mat) {
		for (int i = 0; i < redovi; i++) {
			for (int j = 0; j < stupci; j++) {
				elementi[i][j] += mat.elementi[i][j];
			}
		}
	}

	void oduzmi_matrice(Matrica mat) {
		for (int i = 0; i < redovi; i++) {
			for (int j = 0; j < stupci; j++) {
				elementi[i][j] -= mat.elementi[i][j];
			}
		}
	}

	void pomnozi_matrice(Matrica mat) {
		for (int i = 0; i < redovi; i++) {
			for (int j = 0; j < stupci; j++) {
				elementi[i][j] *= mat.elementi[i][j];
			}
		}
	}

	void transponiraj_matricu() {
		Matrica temp;
		temp.stvori_matricu(stupci, redovi);
		for (int i = 0; i < redovi; i++) {
			for (int j = 0; j < stupci; j++) {
				temp.elementi[j][i] = elementi[i][j];
			}
		}
		dealociraj_matricu();
		stvori_matricu(stupci, redovi);
		for (int i = 0; i < stupci; i++) {
			for (int j = 0; j < redovi; j++) {
				elementi[j][i] = temp.elementi[j][i];
			}
		}
	}

	void ispis_matrice() {
		for (int i = 0; i < redovi; i++) {
			for (int j = 0; j < stupci; j++) {
				std::cout << std::fixed << std::setprecision(4) << elementi[i][j] << "\t";
			}
			std::cout << std::endl;
		}
	}

	void dealociraj_matricu() {
		for (int i = 0; i < redovi; i++) {
			delete[] elementi[i];
		}
		delete[] elementi;
	}
};

int main() {
	Matrica mat1, mat2;
	mat1.stvori_matricu(2, 3);
	mat1.generiraj_matricu(1.0f, 5.0f);
	mat1.ispis_matrice();

	mat2.stvori_matricu(2, 3);
	mat2.generiraj_matricu(1.0f, 5.0f);
	mat2.ispis_matrice();

	mat1.zbroji_matrice(mat2);
	std::cout << "Zbroj matrica: " << std::endl;
	mat1.ispis_matrice();

	mat1.transponiraj_matricu();
	std::cout << "Transponirana matrica: " << std::endl;
	mat1.ispis_matrice();

	mat1.dealociraj_matricu();
	mat2.dealociraj_matricu();

	return 0;
}

