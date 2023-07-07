//
// Created by czarhrs on 3/16/23.
//

#include "file.h"

void read_size(std::ifstream *file, unsigned short *size) {
    *file >> *size;
    *file >> *size;
}

void load_matrix(std::ifstream *file, unsigned short *size, unsigned short *num, unsigned *matrix,
                 unsigned *matrix_counter) {
    ++(*matrix_counter);
    std::cout << "Matriz de número: " << *matrix_counter << std::endl;
    for (unsigned short i = 0; i < *size; i++) {
        for (unsigned short j = 0; j < *size; j++) {
            do {
                *file >> *num;
                if (*num != '\n') {
                    matrix[*size * i + j] = *num;
                    std::cout << matrix[*size * i + j] << ' ';
                }
                if (file->eof()) {
                    break;
                }
            } while (*num == '\n');
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;;
}

void read_row_and_column(unsigned short *row, unsigned short *column) {
    std::cout << "Qual linha deseja começar?" << std::endl;
    std::cin >> *row;
    std::cout << "E qual coluna?" << std::endl;
    std::cin >> *column;
    std::cout << std::endl;
}

void set_inicial_position(unsigned short *row, unsigned short *column, unsigned *counter, unsigned *matrix,
                          unsigned short *size) {
    *counter = matrix[*size * (*row) + (*column)];
    matrix[*size * (*row) + (*column)] = 0;
}
