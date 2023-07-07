#ifndef ITEM_HPP
#define ITEM_HPP

#include <stdlib.h>

#include <iostream>

using namespace std;

class Item {
   public:
    Item* prox;
    pair<int, int> position;
};

#endif