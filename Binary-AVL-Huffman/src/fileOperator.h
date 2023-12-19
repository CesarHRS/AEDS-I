//
// Created by czarhrs on 8/21/23.
//

#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;


#ifndef TRABALHODEAQUECIMENTO_FILEOPERATOR_H
#define TRABALHODEAQUECIMENTO_FILEOPERATOR_H

void openInputFile(ifstream &inputFile);

void openTextFiles(ifstream &inputFile, unsigned fileNumber);

void openStopWordsFile(ifstream &inputFile);

void fillStopWordsTable(ifstream &inputFile, unordered_map<string, unsigned> &stopWordsTable);

void closeFile(ifstream &inputFile);

void fillHashTable(ifstream &inputFile, unordered_map<string, unsigned> &hashTable,
                   unordered_map<string, unsigned> &stopWordsTable, string aux);

#endif //TRABALHODEAQUECIMENTO_FILEOPERATOR_H
