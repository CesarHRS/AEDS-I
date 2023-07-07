#ifndef BFS_HPP
#define BFS_HPP

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <vector>

#include "Queue.hpp"

using namespace std;

class bfs {
   private:
    int tam;  // Size of matrix
    int l;    // line
    int c;    // column

    int steps;  // Number of steps

    Queue queue;
    vector<pair<int, int>> moves;

    void move(int line, int column, char** matrix);
    bool danger(int line, int column, char** matrix);
    bool isValid(int line, int column, char** matrix);

   public:
    bfs();
    void run(char** matrix, int tam);
};

#endif