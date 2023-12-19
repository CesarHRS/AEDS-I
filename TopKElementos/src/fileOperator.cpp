//
// Created by czarhrs on 8/21/23.
//

#include "fileOperator.h"


void openInputFile(ifstream &inputFile, unsigned fileNumber) {
    string aux = "./dataset/input";
    aux += std::to_string(fileNumber);
    aux += ".txt";
    inputFile.open(aux);
}


void openStopWordsFile(ifstream &inputFile) {
    inputFile.open("./dataset/stopwords.txt");
}

void fillStopWordsTable(ifstream &inputFile, unordered_map<string, unsigned> &stopWordsTable) {
    string buffer;

    while (inputFile >> buffer) {
        for (unsigned i = 0; i < buffer.size(); i++) {
            if (ispunct(buffer[i])) {
                buffer.erase(i, 1);
            }
            buffer[i] = tolower(buffer[i]);
            stopWordsTable[buffer]++;
        }
    }
}

void closeFile(ifstream &inputFile) {
    inputFile.close();
}

void fillHashTable(ifstream &inputFile, unordered_map<string, unsigned> &hashTable,
                   unordered_map<string, unsigned> &stopWordsTable) {
    string buffer;

    auto weirdString = {"--", "^", "-", " — ", " —", "—", "”", "“", "-”", "——", "—",};
    auto weirdChar = {'-', '"', '\xE2', '\x80', '\x9D', '\x9C', '\x94'};
    bool error = false;

    while (inputFile >> buffer) {
        if (stopWordsTable.find(buffer) == stopWordsTable.end()) {
            for (unsigned i = 0; i < buffer.size(); i++) {
                for (auto j: weirdString) {
                    if (buffer.find(j) != buffer.npos) {
                        error = true;
                        break;
                    }
                }
                if (error) {
                    break;
                }
                for (auto j: weirdChar) {
                    if (buffer.find(j) != buffer.npos) {
                        error = true;
                        break;
                    }
                }
                if (error) {
                    break;
                }
                    if (ispunct(buffer[i])) {
                        buffer.erase(i, 1);
                        buffer[i] = tolower(buffer[i]);
                    }
                }
            if(!error){
                for(char & i : buffer){
                    i = tolower(i);
                }
                if(stopWordsTable.find(buffer) == stopWordsTable.end() && buffer.size() > 0){
                    hashTable[buffer]++;
                }
            }
            error = false;
        }
    }
}
