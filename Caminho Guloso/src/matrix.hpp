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

    int auxl;
    int auxc;

    int auxValue;
    int auxSum;

    void verifyLeft();
    void verifyLeftDiagonal();
    void verifyBottom();
    void verifyRight();
    void verifyRightDiagonal();

   public:
    Matrix(int tam);  // Matrix quadratic
    Matrix(int lines, int columns);

    void show();
    void readFromFile(FILE* file);
    void solve(int initialLine, int initialColumn);
};

#endif
