//
// Created by czarhrs on 8/17/23.
//

#ifndef TRABALHODEAQUECIMENTO_HEAP_H
#define TRABALHODEAQUECIMENTO_HEAP_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;
#define K 5

struct heap {
private:
    vector<pair<string, unsigned>> h;
public:
    void create(unordered_map<string, unsigned> &hashTable);
    void print();
};

#endif //TRABALHODEAQUECIMENTO_HEAP_H
