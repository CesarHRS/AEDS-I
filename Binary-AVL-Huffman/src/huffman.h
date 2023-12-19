//
// Created by czarhrs on 9/21/23.
//

#ifndef T2_HUFFMAN_H
#define T2_HUFFMAN_H

#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct HuffmanNode {

    HuffmanNode *left;
    HuffmanNode *right;
    string word;
    unsigned value;

    HuffmanNode(): left(nullptr), right(nullptr), word(), value(0) {}

    HuffmanNode(string w, unsigned v) :
            left(nullptr), right(nullptr), word(std::move(w)), value(v) {}

    HuffmanNode(string w, unsigned v, HuffmanNode *l, HuffmanNode *r) :
            left(l),  right(r),  word(std::move(w)), value(v) {}

};

struct huffman {
    vector<HuffmanNode *> forest;
    huffman()= default;
};

void printPreorder(HuffmanNode *root);

void insertInHuffman(huffman *root, string word, unsigned int value);

void createHuffmanTree(huffman *root);

bool compare(HuffmanNode *a, HuffmanNode *b);


#endif //T2_HUFFMAN_H
