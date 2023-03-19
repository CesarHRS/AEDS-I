#include <stdlib.h>

#include <iostream>

#include "matrix.hpp"

using namespace std;

pair<int, int> readInitialPosition() {
    FILE* file = fopen("../config.va", "r");

    if (file == nullptr) {
        return {0, 0};
    }

    pair<int, int> initialPosition;

    fscanf(file, "%d", &initialPosition.first);
    fscanf(file, "%d", &initialPosition.second);

    return initialPosition;
}

void readLinesAndColumns(FILE* file, int* lines, int* columns) {
    fscanf(file, "%d", lines);
    fscanf(file, "%d", columns);
}

FILE* openFileToRead(string filename) {
    FILE* file = fopen(filename.c_str(), "r");

    if (file == nullptr) {
        cout << "Error: could not open input file.\n";
        exit(-1);
    }

    return file;
}

int main() {
    int lines, columns;
    pair<int, int> initialPosition;

    int count = 1;
    int allSum = 0;

    FILE* file = openFileToRead("matrizes.txt");

    pair<int, int> initial = readInitialPosition();

    readLinesAndColumns(file, &lines, &columns);

    Matrix matrix(lines, columns);

    while (!feof(file)) {
        cout << "Matriz " << count << ": ";

        matrix.readFromFile(file);

        allSum += matrix.solve(initial.first, initial.second);

        count++;
    }

    cout << "Soma total: " << allSum << endl;

    fclose(file);
    return 0;
}