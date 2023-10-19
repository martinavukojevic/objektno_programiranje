#include <stdio.h>

void funkcija(int* niz, int& min, int& max, int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (niz[i] < min) {
            min = niz[i];
        }
        if (niz[i] > max) {
            max = niz[i];
        }
    }
}

int main() {
    int niz[] = { 3, 5, 2, 7, 1, 8, 0 };
    int n = 7;

    int min = niz[0];
    int max = niz[0];

    funkcija(niz, min, max, n);

    printf("Najmanji broj: %d\n", min);
    printf("Najveći broj: %d\n", max);

    return 0;
}
