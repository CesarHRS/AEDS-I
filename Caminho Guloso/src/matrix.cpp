#include "matrix.hpp"

Matrix::Matrix() {
    this->lines = 0;
    this->columns = 0;

    this->auxSum = 0;
    this->totalSum = 0;

    this->matrixCount = 0;
}

Matrix::Matrix(string filename) {
    this->file = fopen(filename.c_str(), "r");

    this->lines = 0;
    this->columns = 0;

    this->auxSum = 0;
    this->totalSum = 0;

    this->matrixCount = 0;
}

Matrix::~Matrix() { fclose(this->file); }

bool Matrix::isFileOpen() {
    return !feof(this->file);
}

void Matrix::readLinesAndColums() {
    File::readLinesAndColumns(file, &lines, &columns);
}

void Matrix::printMatrixIndex() {
    cout << "Matriz " << this->matrixCount << ": ";
}

void Matrix::printTotalSum() { cout << "Soma total: " << totalSum << endl; }

pair<int, int> Matrix::bestMove() {
    int auxValue = 0;

    int auxl;
    int auxc;

    verifyLeft(&auxl, &auxc, &auxValue);
    verifyLeftDiagonal(&auxl, &auxc, &auxValue);
    verifyBottom(&auxl, &auxc, &auxValue);
    verifyRight(&auxl, &auxc, &auxValue);
    verifyRightDiagonal(&auxl, &auxc, &auxValue);

    pair<int, int> move;
    move.first = auxl;
    move.second = auxc;

    return move;
}

void Matrix::solve(int* initialLine, int* initialColumn) {
    if (*initialLine < 0 || *initialLine > lines - 1) {
        cout << "Invalid inital line value!\n";
        exit(-1);
    }

    if (*initialColumn < 0 || *initialColumn > columns - 1) {
        cout << "Invalid inital column value!\n";
        exit(-1);
    }

    auxSum = 0;

    line = *initialLine;
    column = *initialColumn;

    while (line != lines - 1 || column != columns - 1) {
        cout << matrix[line][column] << " + ";

        auxSum += matrix[line][column];
        matrix[line][column] = -1;

        pair<int, int> best = bestMove();

        line = best.first;
        column = best.second;
    }

    // Mostrando ultima posicao
    cout << matrix[line][column];

    auxSum += matrix[line][column];

    cout << " = " << auxSum << endl << endl;

    this->totalSum += auxSum;
}

void Matrix::verifyRight(int* auxl, int* auxc, int* auxValue) {
    if (column + 1 != columns) {
        int rightValue = matrix[line][column + 1];

        if (rightValue != -1 && *auxValue <= rightValue) {
            *auxValue = rightValue;
            *auxl = line;
            *auxc = column + 1;
        }
    }
}

void Matrix::verifyRightDiagonal(int* auxl, int* auxc, int* auxValue) {
    if (line + 1 != lines && column + 1 != columns) {
        int rightDiagonalValue = matrix[line + 1][column + 1];

        if (rightDiagonalValue != -1 && *auxValue <= rightDiagonalValue) {
            *auxValue = rightDiagonalValue;
            *auxl = line + 1;
            *auxc = column + 1;
        }
    }
}

void Matrix::verifyBottom(int* auxl, int* auxc, int* auxValue) {
    if (line + 1 != lines) {
        int bottomValue = matrix[line + 1][column];

        if (bottomValue != -1 && *auxValue <= bottomValue) {
            *auxValue = bottomValue;
            *auxl = line + 1;
            *auxc = column;
        }
    }
}

void Matrix::verifyLeftDiagonal(int* auxl, int* auxc, int* auxValue) {
    if (line + 1 != lines && column - 1 >= 0) {
        int leftDiagonalValue = matrix[line + 1][column - 1];

        if (leftDiagonalValue != -1 && *auxValue <= leftDiagonalValue) {
            *auxValue = leftDiagonalValue;
            *auxl = line + 1;
            *auxc = column - 1;
        }
    }
}

void Matrix::verifyLeft(int* auxl, int* auxc, int* auxValue) {
    if (column - 1 >= 0 && line != lines - 1) {
        int leftValue = matrix[line][column - 1];

        if (leftValue != -1 && *auxValue <= leftValue) {
            *auxValue = leftValue;
            *auxl = line;
            *auxc = column - 1;
        }
    }
}

void Matrix::show() {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) cout << matrix[i][j] << "\t";
        cout << endl;
    }

    cout << endl << "-----" << endl;
};

void Matrix::readNextMatrix() {
    matrix.clear();

    File::readMatrix(file, &matrix, &lines, &columns);

    this->matrixCount++;
}