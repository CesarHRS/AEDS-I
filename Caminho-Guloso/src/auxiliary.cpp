//
// Created by czarhrs on 3/15/23.
//

#include "auxiliary.h"

void print(unsigned *matrix, unsigned short size) {
    for (unsigned short i = 0; i < size; i++) {
        for (unsigned short j = 0; j < size; j++) {
            std::cout << matrix[size * i + j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}


void right(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (*row) + (++(*column))];
    matrix[size * (*row) + (*column)] = 0;
}

void down(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (++(*row)) + (*column)];
    matrix[size * (*row) + (*column)] = 0;
}

void left(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (*row) + (--(*column))];
    matrix[size * (*row) + (*column)] = 0;
}

void
right_diagonal(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (++(*row)) + (++(*column))];
    matrix[size * (*row) + (*column)] = 0;
}

void
left_diagonal(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    *counter += matrix[size * (++(*row)) + (--(*column))];
    matrix[size * (*row) + (*column)] = 0;
}
