#include "Queue.hpp"

Queue::Queue() {
    this->_front = nullptr;
    this->_back = nullptr;

    this->_size = 0;
}

int Queue::size() { return this->_size; }

Item Queue::front() {
    if (empty()) {
        throw std::out_of_range("A fila está vazia");
    }

    return *_front;
}

void Queue::push(pair<int, int> position) {
    Item* newNode = new Item();
    newNode->position = position;

    if (empty()) {
        _front = _back = newNode;
    } else {
        _back->prox = newNode;
        _back = newNode;
    }

    this->_size++;
}

void Queue::pop() {
    if (empty()) {
        throw std::out_of_range("A fila está vazia");
    }

    Item* temp = _front;
    _front = _front->prox;

    delete temp;

    this->_size--;
}

bool Queue::empty() { return this->_size == 0; }