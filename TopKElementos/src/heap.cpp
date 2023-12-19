//
// Created by czarhrs on 8/17/23.
//

#include "heap.h"

void heap::create(unordered_map<string, unsigned int> &hashTable) {

    for (auto &pair: hashTable) {
        h.emplace_back(pair);
        unsigned long i = h.size() - 1;
        unsigned long aux = (i - 1) / 2;
        while (h[i].second > h[aux].second) {
            swap(h[i], h[aux]);
            i = aux;
            aux = (i - 1) / 2;
        }
    }

    print();
}

void heap::print() {
    for (unsigned i = 0; i < K; i++) {
        cout << "Posição " << i << " ";
        cout << "Palavra: " << h[i].first << " - Frequência: " << h[i].second << endl;
    }
}
