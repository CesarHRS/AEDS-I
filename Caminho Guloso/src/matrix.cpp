#include "matrix.hpp"

Matrix::Matrix(int tam) {
    this->lines = tam;
    this->columns = tam;
}

Matrix::Matrix(int lines, int columns) {
    this->lines = lines;
    this->columns = columns;
}

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

int Matrix::solve(int initialLine, int initialColumn) {
    if (initialLine < 0 || initialLine > lines - 1) {
        cout << "Invalid inital line value!\n";
        exit(-1);
    }

    if (initialColumn < 0 || initialColumn > columns - 1) {
        cout << "Invalid inital column value!\n";
        exit(-1);
    }

    auxSum = 0;

    line = initialLine;
    column = initialColumn;

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
    return auxSum;
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

void Matrix::readFromFile(FILE* file) {
    matrix.clear();

    for (int i = 0; i < lines; i++) {
        vector<int> line;

        for (int j = 0; j < columns; j++) {
            int num;
            fscanf(file, "%d", &num);
            line.push_back(num);
        }

        matrix.push_back(line);
    }
}