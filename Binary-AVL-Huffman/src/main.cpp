#include <chrono>
#include <queue>
#include "heap.h"
#include "fileOperator.h"

using namespace std;
#define qnt  1

int main() {
    heap h;
    ifstream inputFile, file;
    AVLNode *AVLroot = nullptr;
    BNode *Broot = nullptr;
    huffman *Hroot = nullptr;

    string inputWord;
    unordered_map<string, unsigned> stopWordsTable;
    unordered_map<string, unsigned> hashTable;

    openInputFile(inputFile);
    openStopWordsFile(file);


    fillStopWordsTable(file, stopWordsTable);
    closeFile(file);


    while (inputFile >> inputWord) {
        for (unsigned short i = 0; i < qnt; i++) {

            openTextFiles(file, i);
            fillHashTable(file, hashTable, stopWordsTable, inputWord);
            closeFile(file);
            h.createHeap(hashTable);


            //começa AVL
            auto start = chrono::steady_clock::now();

            h.insertInAVL(AVLroot);
            printPreorder(AVLroot);

            auto elapsedTime = chrono::steady_clock::now() - start;
            double duration = chrono::duration_cast<chrono::duration<double>>(elapsedTime).count();
            cout << "Tempo para inserir e imprimir a arvore AVL: " << duration << endl;

            cout << endl << endl << endl;

            // Começa Binária
            start = chrono::steady_clock::now();

            h.insertInBinary(Broot);
            printPreorder(Broot);

            elapsedTime = chrono::steady_clock::now() - start;
            duration = chrono::duration_cast<chrono::duration<double>>(elapsedTime).count();
            cout << "Tempo para inserir e imprimir a arvore binária: " << duration << endl;

            cout << endl << endl << endl;


            // Começa Huffman
            start = chrono::steady_clock::now();

            Hroot = new huffman();
            h.insertInHuffman(Hroot);
            printPreorder(Hroot->forest[0]);

            elapsedTime = chrono::steady_clock::now() - start;
            duration = chrono::duration_cast<chrono::duration<double>>(elapsedTime).count();
            cout << "Tempo para inserir e imprimir a arvore huffman: " << duration << endl;

            h.clearHeap();

        }


    }

    return 0;
}