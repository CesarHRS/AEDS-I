#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdlib.h>

#include <iostream>

#include "Item.hpp"

using namespace std;

class Queue {
   private:
    Item* _front;
    Item* _back;

    int _size;

   public:
    Queue();
    int size();
    Item front();
    void push(pair<int, int> position);
    void pop();
    bool empty();
};

#endif