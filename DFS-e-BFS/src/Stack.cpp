#include "Stack.hpp"

Stack::Stack() {
    this->_top = nullptr;
    this->_size = 0;
}

int Stack::size() { return this->_size; }

Item Stack::top() { return *this->_top; }

void Stack::push( pair<int, int> position) {
    Item *newItem;

    newItem = (Item *)malloc(sizeof(Item));

    newItem->position = position;

    newItem->prox = _top;

    _top = newItem;
    this->_size++;
}

void Stack::pop() {
    if (this->_top == nullptr) return;

    Item *aux = this->_top;

    this->_top = this->_top->prox;

    free(aux);
    this->_size--;
}

bool Stack::empty() {
    if (this->_top == nullptr) return true;
    return false;
}