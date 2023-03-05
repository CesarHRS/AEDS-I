#include <stdlib.h>

#include <iostream>

#include "matrix.hpp"

using namespace std;

int main() {

    FILE* file = fopen("matrizes.txt", "r");

    if (file == nullptr) {
        cout << "Error: could not open input file.\n";
        exit(-1);
    }

    int n;  // Número de matrizes
    fscanf(file, "%d", &n);

    int tam;  // Tamanho da matriz, l por l
    fscanf(file, "%d", &tam);

    while (n--) {
        Matrix matrix(tam);

        //matrix.readFromStdin();
        matrix.readFromFile(file);

        matrix.solve(0, 0);
        matrix.show();

    }

    fclose(file);
    return 0;
}