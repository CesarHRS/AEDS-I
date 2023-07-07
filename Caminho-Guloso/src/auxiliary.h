//
// Created by czarhrs on 3/15/23.
//

#ifndef OCAMINHODOGULOSO_AUXILIARY_H
#define OCAMINHODOGULOSO_AUXILIARY_H
#include <iostream>
#include <fstream>


void print(unsigned *matrix, unsigned short size);
void right(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
void down(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
void left(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
void right_diagonal(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);
void left_diagonal(unsigned *matrix, unsigned short size, unsigned short *row, unsigned short *column, unsigned *counter);


#endif //OCAMINHODOGULOSO_AUXILIARY_H
