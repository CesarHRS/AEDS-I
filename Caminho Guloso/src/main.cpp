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

    int lines;  // Number of lines
    fscanf(file, "%d", &lines);

    int columns;  // Number of columns
    fscanf(file, "%d", &columns);

    Matrix matrix(lines, columns);

    while (!feof(file)) {
        matrix.readFromFile(file);

        matrix.solve(0, 0);
        matrix.show();
    }

    fclose(file);
    return 0;
}