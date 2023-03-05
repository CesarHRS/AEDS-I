#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <stdlib.h>
#include <iostream>

#include <vector>

using namespace std;

class Matrix {
   private:
    int tam;  // Tamanho da matriz
    vector<vector<int>> matrix;

    int line;
    int column;

    int auxl;
    int auxc;

    int auxValue = 0;

    void verifyLeft();
    void verifyLeftDiagonal();
    void verifyBottom();
    void verifyRight();
    void verifyRightDiagonal();

   public:
    Matrix(int tam);

    void show();
    void readFromFile(FILE* file);
    void readFromStdin();
    void solve(int initialLine, int initialColumn);
};

#endif
