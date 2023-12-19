//
// Created by czarhrs on 9/20/23.
//

#ifndef T2_AVL_H
#define T2_AVL_H

#include <string>
#include <utility>

using namespace std;

struct AVLNode {
    std::string value;
    unsigned int key;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode(std::string k, unsigned int v) : value(std::move(k)), key(v), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(AVLNode *node);

int getBalanceFactor(AVLNode *node);

void updateHeight(AVLNode *node);

AVLNode *rotateRight(AVLNode *y);

AVLNode *rotateLeft(AVLNode *x);

AVLNode *insert(AVLNode *root, const std::string &value, unsigned int key);

void printPreorder(AVLNode *root);


#endif //T2_AVL_H
