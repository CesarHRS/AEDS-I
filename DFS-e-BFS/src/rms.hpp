#ifndef RMS_HPP
#define RMS_HPP

#include <stdlib.h>
#include <unistd.h>

#include <iostream>
#include <random>
#include <vector>

#include "Stack.hpp"

using namespace std;

// Random Method Search
class rms {
   private:
    int tam;  // Size of matrix
    int l;    // line
    int c;    // column

    int steps;  // Number of steps

    Stack stack;
    vector<pair<int, int>> moves;

    bool move(char** matrix);
    void danger(char** matrix);
    vector<pair<int, int>> getAllPossibilites(char** matrix);

    int randomInt(int min, int max);

   public:
    rms();
    void run(char** matrix, int tam);
};

#endif