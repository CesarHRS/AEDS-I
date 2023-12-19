//
// Created by czarhrs on 9/20/23.
//

#include <iostream>
#include "AVL.h"


int getHeight(AVLNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

int getBalanceFactor(AVLNode *node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(AVLNode *node) {
    if (node != nullptr) {
        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    }
}

AVLNode *rotateRight(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

AVLNode *rotateLeft(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

AVLNode *insert(AVLNode *root, const std::string &value, unsigned int key) {
    if (root == nullptr) {
        return new AVLNode(value, key);
    }

    if (key < root->key) {
        root->left = insert(root->left, value, key);
    } else if (key > root->key) {
        root->right = insert(root->right, value, key);
    } else {
        return root;
    }

    updateHeight(root);

    int balance = getBalanceFactor(root);

    if (balance > 1) {
        if (key < root->left->key) {
            return rotateRight(root);
        } else {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
    }

    if (balance < -1) {
        if (key > root->right->key) {
            return rotateLeft(root);
        } else {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }
    }

    return root;
}

void printPreorder(AVLNode *root) {
    if (root == nullptr) {
        return;
    }

    cout << "Key: " << root->value << ", Value: " << root->key << endl;
    printPreorder(root->left);
    printPreorder(root->right);
}
