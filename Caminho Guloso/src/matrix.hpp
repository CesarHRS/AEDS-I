#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdlib.h>

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
   private:
    int lines;
    int columns;
    vector<vector<int>> matrix;

    int line;
    int column;

    int auxSum;

    pair<int, int> bestMove();

    void verifyLeft(int* auxl, int* auxc, int* auxValue);
    void verifyLeftDiagonal(int* auxl, int* auxc, int* auxValue);
    void verifyBottom(int* auxl, int* auxc, int* auxValue);
    void verifyRight(int* auxl, int* auxc, int* auxValue);
    void verifyRightDiagonal(int* auxl, int* auxc, int* auxValue);

   public:
    Matrix(int tam);  // Matrix quadratic
    Matrix(int lines, int columns);

    void show();
    void readFromFile(FILE* file);
    int solve(int initialLine, int initialColumn);
};

#endif
