//
// Created by czarhrs on 8/17/23.
//

#ifndef TRABALHODEAQUECIMENTO_HEAP_H
#define TRABALHODEAQUECIMENTO_HEAP_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include "AVL.h"
#include "bynaryTree.h"
#include "huffman.h"

using namespace std;
#define K 20

struct heap {
private:
    vector<pair<string, unsigned>> h;
public:
    void createHeap(unordered_map<string, unsigned> &hashTable);

    void print();

    void insertInAVL(AVLNode(*&root));

    void insertInBinary(BNode(*&root));

    void insertInHuffman(huffman(*&root));

    void clearHeap();
};

#endif //TRABALHODEAQUECIMENTO_HEAP_H
