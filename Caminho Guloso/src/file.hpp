#ifndef FILE_HPP
#define FILE_HPP

#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

class File {
   public:
    static void readInitialPosition(string configFileName, int* initialLine,
                                    int* initialColumn);
    static void readLinesAndColumns(FILE* file, int* lines, int* columns);
    static FILE* openFileToRead(string filename);
    static void readMatrix(FILE* file, vector<vector<int>>* matrix, int* lines, int* columns);
};

#endif
