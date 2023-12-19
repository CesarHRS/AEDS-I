//
// Created by czarhrs on 9/20/23.
//

#include "bynaryTree.h"

BNode* insert(BNode* root, const std::string& value, unsigned int key) {
    if (root == nullptr) {
        return new BNode(value, key);
    }

    if (key < root->key) {
        root->left = insert(root->left, value, key);
    } else if (key > root->key) {
        root->right = insert(root->right, value, key);
    }

    return root;
}

void printPreorder(BNode* root) {
    if (root != nullptr) {
        std::cout << "Key: " << root->key << ", Value: " << root->value << endl;
        printPreorder(root->left);
        printPreorder(root->right);
    }
}
