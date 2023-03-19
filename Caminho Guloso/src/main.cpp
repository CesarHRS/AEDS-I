#include <stdlib.h>

#include <iostream>

#include "file.hpp"
#include "matrix.hpp"

using namespace std;

int main() {
    int initialLine, initialColumn;
    File::readInitialPosition("config.va", &initialLine, &initialColumn);

    Matrix matrix("matrizes.txt");

    matrix.readLinesAndColums();

    while (!feof(matrix.file)) {
        matrix.printMatrixIndex();

        matrix.readNextMatrix();

        matrix.solve(&initialLine, &initialColumn);
    }

    matrix.printTotalSum();

    return 0;
}