#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdlib.h>

#include <iostream>
#include <vector>

#include "file.hpp"

using namespace std;

class Matrix {
   private:
    int lines; // Number of lines
    int columns; // Number of columns
    int matrixCount; // Index of actual matrix
    vector<vector<int>> matrix; // Actual matrix

    int line; // Actual line
    int column; // Actual column

    int auxSum; // Sum of actual matrix
    int totalSum; // Sum of all matrix

    pair<int, int> bestMove();

    void verifyLeft(int* auxl, int* auxc, int* auxValue);
    void verifyLeftDiagonal(int* auxl, int* auxc, int* auxValue);
    void verifyBottom(int* auxl, int* auxc, int* auxValue);
    void verifyRight(int* auxl, int* auxc, int* auxValue);
    void verifyRightDiagonal(int* auxl, int* auxc, int* auxValue);

   public:
    Matrix();
    Matrix(string filename);

    ~Matrix();

    FILE* file;

    void show();

    bool isFileOpen();

    void readLinesAndColums();
    void readNextMatrix();
    void solve(int* initialLine, int* initialColumn);

    void printMatrixIndex();
    void printTotalSum();
};

#endif
