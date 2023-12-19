//
// Created by czarhrs on 9/20/23.
//

#ifndef T2_BYNARYTREE_H
#define T2_BYNARYTREE_H

#include <string>
#include <iostream>


using namespace std;

struct BNode {
    std::string value;
    unsigned int key;
    BNode* left;
    BNode* right;

    BNode(const std::string& k, unsigned int v) : value(k), key(v), left(nullptr), right(nullptr) {}
};


BNode* insert(BNode* root, const std::string& value, unsigned int key);
void printPreorder(BNode* root);


#endif //T2_BYNARYTREE_H
