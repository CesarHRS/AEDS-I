//
// Created by cesar on 27/04/2023.
//

#ifndef DFS_E_BFS_FILEOPERATOR_H
#define DFS_E_BFS_FILEOPERATOR_H

#include <vector>
#include <tuple>
#include "fstream"

class FileOperator {
private:
    std::ifstream inputFile;
    std::pair<unsigned, unsigned> Dimensions; // .first = lines and second = columns
public:
    FileOperator(); // just a simple constructor
    void openFile(); // open the file
    void closeFile(); // close the file
    std::pair<unsigned, unsigned> readFileHeader(); // read the file header
    char ReadDataFromFile(); // read a single char from the file and returns its value if its not a '\n'
    void saveMatrixOnFile(char** matrix, std::string filename);
};


#endif //DFS_E_BFS_FILEOPERATOR_H
