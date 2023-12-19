//
// Created by czarhrs on 8/17/23.
//

#include "heap.h"

void heap::createHeap(unordered_map<string, unsigned int> &hashTable) {
    unsigned aux = 100000000;
    long i_aux;
    for (auto &pair: hashTable) {
        if(h.size() == 20){
            for(long i = 0; i < h.size(); i++){
                if(h[i].second > aux){
                    aux = h[i].second;
                    i_aux = i;
                }
            }
            h.erase(h.begin()+i_aux);
        }
        h.emplace_back(pair);
        long i = h.size() - 1;
        long aux = (i - 1) / 2;
        while (h[i].second > h[aux].second) {
            swap(h[i], h[aux]);
            i = aux;
            aux = (i - 1) / 2;
        }
    }
}

void heap::print() {
    for (unsigned i = 0; i < h.size(); i++) {
        cout << "Posição " << i << " ";
        cout << "Palavra: " << h[i].first << " - Frequência: " << h[i].second << endl;
    }
}

void heap::insertInAVL(AVLNode(*& root)) {
    for (unsigned i = 0; i < K; i++) {
        root = insert(root, h[i].first, h[i].second);
    }
}

void heap::insertInBinary(BNode *&root) {
    for (unsigned i = 0; i < K; i++) {
        root = insert(root, h[i].first, h[i].second);
    }
}

void heap::insertInHuffman(huffman *&root) {
    for(unsigned i = 0; i < K; i++){
        ::insertInHuffman(root, h[i].first, h[i].second);
    }
    createHuffmanTree(root);
}

void heap::clearHeap() {
        h.clear();
}

