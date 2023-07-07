//
// Created by cesar on 28/04/2023.
//

#ifndef DFS_E_BFS_MATRIX_H
#define DFS_E_BFS_MATRIX_H
#include <utility>
#include <cstdlib>
#include <tuple>
#include <iostream>

class Matrix {
private:
    char **matrix; // all the content of the matrix is here
    std::pair<unsigned, unsigned> matrixDimensions; // .first = lines and second = columns
public:
    Matrix(); // just a simple constructor
    char** getCopyOfMatrix();
    std::pair<unsigned, unsigned> getMatrixDimensions(); // returns matrixDimensions
    void setMatrixDimensions(std::pair<unsigned, unsigned> mazeDimensions); // sets the matrixDimensions. !Important! do this before allocating the matrix!
    void allocateMatrix(); // allocates the matrix according with its dimensions
    void loadContentInMatrix(unsigned i, unsigned j, char content); // at each iteration, this fuction stores a given data in the matrix
    void printMatrix(); // prints the whole matrix


};


#endif //DFS_E_BFS_MATRIX_H
