//
// Created by cesar on 28/04/2023.
//

#include "Matrix.h"

Matrix::Matrix() {
    matrix = nullptr;
    matrixDimensions.first = 0;
    matrixDimensions.second = 0;
}

std::pair<unsigned, unsigned> Matrix::getMatrixDimensions() {
    return matrixDimensions;
}

void Matrix::setMatrixDimensions(std::pair<unsigned, unsigned> Dimensions) {
    matrixDimensions = Dimensions;
}

char** Matrix::getCopyOfMatrix() {
    char** copy = new char*[matrixDimensions.first];

    for (unsigned i = 0; i < matrixDimensions.first; i++) {
        copy[i] = new char[matrixDimensions.second];
    }

    for (unsigned i = 0; i < matrixDimensions.first; i++) {
        for (unsigned j = 0; j < matrixDimensions.second; j++) {
            copy[i][j] = matrix[i][j];
        }
    }

    return copy;
}

void Matrix::allocateMatrix() {
    matrix = new char*[matrixDimensions.first];
    for (unsigned i = 0; i < matrixDimensions.first; i++) {
        matrix[i] = new char[matrixDimensions.second];
    }
}

void Matrix::loadContentInMatrix(unsigned i, unsigned j, char content) {
    matrix[i][j] = content;
}

void Matrix::printMatrix() {
    for (unsigned i = 0; i < matrixDimensions.first; i++) {
        for (unsigned j = 0; j < matrixDimensions.second; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
