//
// Created by czarhrs on 3/15/23.
//

#include "joystick.h"


void joystick(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter) {
    do {
        if ((*row == (size - 1) && *row == *column)) {
            break;
        } else if (*row == (size - 1)) {
            right(matrix, size, &(*row), &(*column), &(*counter));
        } else if (*column == (size - 1)) {
            if (matrix[size * ((*row) + 1) + (*column)] >= matrix[size * ((*row) + 1) + ((*column) - 1)] &&
                matrix[size * ((*row) + 1) + (*column)] >= matrix[size * (*row) + ((*column) - 1)]) {
                down(matrix, size, &(*row), &(*column), &(*counter));
            } else if (matrix[size * (*row) + ((*column) - 1)] >= matrix[size * ((*row) + 1) + ((*column) - 1)]) {
                left(matrix, size, &(*row), &(*column), &(*counter));
            } else {
                left_diagonal(matrix, size, &(*row), &(*column), &(*counter));
            }
        } else if (*column == 0) {
            if (matrix[size * ((*row) + 1) + ((*column) + 1)] >= matrix[size * ((*row) + 1) + (*column)] &&
                matrix[size * ((*row) + 1) + ((*column) + 1)] >= matrix[size * (*row) + ((*column) + 1)]) {
                right_diagonal(matrix, size, &(*row), &(*column), &(*counter));
            } else if (matrix[size * (*row) + ((*column) + 1)] >= matrix[size * ((*row) + 1) + (*column)]) {
                right(matrix, size, &(*row), &(*column), &(*counter));
            } else {
                down(matrix, size, &(*row), &(*column), &(*counter));
            }
        } else if (matrix[size * ((*row) + 1) + ((*column) + 1)] >= matrix[size * (*row) + ((*column) + 1)] &&
                   matrix[size * ((*row) + 1) + ((*column) + 1)] >= matrix[size * ((*row) + 1) + (*column)] &&
                   matrix[size * ((*row) + 1) + ((*column) + 1)] >= matrix[size * (*row) + ((*column) - 1)] &&
                   matrix[size * ((*row) + 1) + ((*column) + 1)] >= matrix[size * ((*row) + 1) + ((*column) - 1)]) {
            right_diagonal(matrix, size, &(*row), &(*column), &(*counter));
        } else if (matrix[size * (*row) + ((*column) + 1)] >= matrix[size * ((*row) + 1) + (*column)] &&
                   matrix[size * (*row) + ((*column) + 1)] >= matrix[size * (*row) + ((*column) - 1)] &&
                   matrix[size * (*row) + ((*column) + 1)] >= matrix[size * ((*row) + 1) + ((*column) - 1)]) {
            right(matrix, size, &(*row), &(*column), &(*counter));
        } else if (matrix[size * ((*row) + 1) + (*column)] >= matrix[size * ((*row) + 1) + ((*column) - 1)] &&
                   matrix[size * ((*row) + 1) + (*column)] >= matrix[size * (*row) + ((*column) - 1)]) {
            down(matrix, size, &(*row), &(*column), &(*counter));
        } else if (matrix[size * (*row) + (*column - 1)] >= matrix[size * ((*row) + 1) + ((*column) - 1)])
            left(matrix, size, &(*row), &(*column), &(*counter));
        else {
            left_diagonal(matrix, size, &(*row), &(*column), &(*counter));
        }
    } while (true);
}

