#ifndef STACK_HPP
#define STACK_HPP

#include <stdlib.h>

#include <iostream>

#include "Item.hpp"

using namespace std;

class Stack {
   private:
    Item* _top;
    int _size;

   public:
    Stack();
    int size();
    Item top();
    void push(pair<int, int> position);
    void pop();
    bool empty();
};

#endif