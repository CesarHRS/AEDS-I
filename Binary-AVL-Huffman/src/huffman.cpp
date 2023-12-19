//
// Created by czarhrs on 9/21/23.
//

#include "huffman.h"


void printPreorder(HuffmanNode *root) {
    if (root != nullptr) {
        printPreorder(root->left);
        if (root->word != "%") {
            cout << "Key: " << root->word << ", Value: " << root->value << endl;
        }
        printPreorder(root->right);
    }
}

void insertInHuffman(huffman *root, string word, unsigned int value) {
    root->forest.push_back(new HuffmanNode(std::move(word), value));
}

void createHuffmanTree(huffman *root) {
    while (root->forest.size() > 1) {
        std::sort(root->forest.begin(), root->forest.end(), compare);
        auto a = root->forest[0];
        auto b = root->forest[1];
        auto c = new HuffmanNode("%", a->value + b->value, a, b);
        root->forest.erase(root->forest.begin());
        root->forest.erase(root->forest.begin());
        root->forest.push_back(c);
    }
}

bool compare(HuffmanNode *a, HuffmanNode *b) {
    return (a->value < b->value);
}
