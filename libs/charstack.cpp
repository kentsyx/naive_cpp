/* File: charstack.cpp
 * -------------------
 * This file implements the charstack.h interface.
 */

#include "charstack.h"
#include "error.h"

CharStack::CharStack() {
    capacity = INITIAL_CAPACITY;
    array = new char[capacity];
    count = 0;
}

CharStack::CharStack(const CharStack& src) {
    deepCopy(src);
}

CharStack& CharStack::operator=(const CharStack& src) {
    if (this != &src) {
        delete[] array;
        deepCopy(src);
    }
    return *this;
}

CharStack::~CharStack() {
    delete[] array;
}

int CharStack::size() const {
    return count;
}

bool CharStack::empty() const {
    return count == 0;
}

void CharStack::clear() {
    count = 0;
}

void CharStack::push(char ch) {
    if (count == capacity)
        expandCapacity();
    array[count++] = ch;
}

char CharStack::pop() {
    if (empty())
        error("Attempting to pop on an empty stack.");
    return array[--count];
}

char CharStack::top() const {
    if (empty())
        error("Attempting to top on an empty stack.");
    return array[count - 1];
}

void CharStack::deepCopy(const CharStack& src) {
    array = new char[src.count];
    for (int i = 0; i != src.count; ++i)
        array[i] = src.array[i];
    count = src.count;
    capacity = src.capacity;
}

void CharStack::expandCapacity() {
    char *oldArray = array;
    capacity *= 2;
    array = new char[capacity];
    for (int i = 0; i != count; ++i)
        array[i] = oldArray[i];
    delete[] oldArray;
}
