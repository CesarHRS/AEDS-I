//
// Created by cesar on 27/04/2023.
//

#include "FileOperator.h"

FileOperator::FileOperator() {
    // inputFile;
    Dimensions.first = 0;
    Dimensions.second = 0;
}

void FileOperator::openFile() { inputFile.open("dataset/input.data"); }

void FileOperator::closeFile() { inputFile.close(); }

std::pair<unsigned, unsigned> FileOperator::readFileHeader() {
    inputFile >> Dimensions.first;
    inputFile >> Dimensions.second;

    int aux;
    inputFile >> aux;

    return Dimensions;
}

char FileOperator::ReadDataFromFile() {
    char buffer;
    inputFile >> buffer;
    if (buffer != '\n') {
        return buffer;
    }
    return ' ';
}

void FileOperator::saveMatrixOnFile(char** matrix, std::string filename) {
    std::ofstream file;
    file.open(filename);

    for (unsigned i = 0; i < Dimensions.first; i++) {
        for (unsigned j = 0; j < Dimensions.second; j++) {
            file << matrix[i][j] << " ";
        }
        file << std::endl;
    }
}
