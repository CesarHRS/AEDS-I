//
// Created by czarhrs on 3/16/23.
//

#ifndef OCAMINHODOGULOSO_ARQUIVO_H
#define OCAMINHODOGULOSO_ARQUIVO_H
#include <fstream>
#include <iostream>

void read_size(std::ifstream *file, unsigned short *size);
void load_matrix(std::ifstream *file, unsigned short *size, unsigned short *num, unsigned *matrix, unsigned *matrix_counter);
void read_row_and_column(unsigned short *row, unsigned short *column);
void set_inicial_position(unsigned short *row, unsigned short *column, unsigned *counter, unsigned *matrix, unsigned short *size);

#endif //OCAMINHODOGULOSO_ARQUIVO_H
