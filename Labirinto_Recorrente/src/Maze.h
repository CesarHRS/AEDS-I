//
// Created by cesar on 04/04/2023.
//

#ifndef O_LABIRINTO_RECORRENTE_MAZE_H
#define O_LABIRINTO_RECORRENTE_MAZE_H

#include <fstream>
#include "Boy.h"

class Maze {
private:
    std::pair<short, short> mazeDimensions; // primeiro = largura ou altura da matriz, no caso a mesma coisa e second é a quantidade de matrizes que existem no arquivo.
    Boy boy;
    unsigned short matrixNumber;
    char **matrix;
    bool **booleanMatrix;
public:
    Maze();

    void allocate();

    void readHeader();

    void separateMatrix();

    void loadMatrix();

    void loadSpecificMatrix(unsigned short specificMatrixNumber);

    void saveMatrix();

    void getInitialPosition();

    void joystick();

    void tryPosition(short x, short y);

    bool haveExploredAllMatrixes();

    bool haveWalkedToInitialPosition();

    void endGame();

    void print();
};

#endif //O_LABIRINTO_RECORRENTE_MAZE_H
