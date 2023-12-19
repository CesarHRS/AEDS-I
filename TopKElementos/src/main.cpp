#include <chrono>
#include "heap.h"
#include "fileOperator.h"

using namespace std;

#define qnt 1

void printHashTable(const unordered_map<string, unsigned> &hashTable) {
    for (const auto &pair: hashTable) {
        const string &word = pair.first;
        unsigned cont = pair.second;
        cout << "Palavra: " << word << " - Frequência: " << cont << endl;
    }
}

auto loadHashOnMemory(const unordered_map<string, unsigned> &hashTable) {
    vector<pair<string, unsigned>> aux;
    for (const auto &pair: hashTable) {
        aux.emplace_back(pair);
    }
    return aux;
}


int main() {
    heap h;

    ifstream inputFile;
    unordered_map<string, unsigned> stopWordsTable;
    unordered_map<string, unsigned> hashTable;

    openStopWordsFile(inputFile);
    fillStopWordsTable(inputFile, stopWordsTable);
    closeFile(inputFile);

    for (unsigned short i = 0; i < qnt; i++) {

        auto start = chrono::steady_clock::now();


        openInputFile(inputFile, i);
        fillHashTable(inputFile, hashTable, stopWordsTable);
        closeFile(inputFile);
        //printHashTable(hashTable);
        h.create(hashTable);
        auto elapsedTime = chrono::steady_clock::now() - start;
        double duration =
                chrono::duration_cast<chrono::duration<double>>(elapsedTime).count();
        //cout << duration << endl;
    }


    return 0;
}