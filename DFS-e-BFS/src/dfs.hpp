#ifndef DFS_HPP
#define DFS_HPP

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <vector>

#include "Stack.hpp"

using namespace std;

class dfs {
   private:
    int tam;  // Size of matrix
    int l;    // line
    int c;    // column

    int steps;  // Number of steps

    Stack stack;
    vector<pair<int, int>> moves;

    bool move(int line, int column, char** matrix);
    void danger(char** matrix);

   public:
    dfs();
    void run(char** matrix, int tam);
};

#endif