#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

/* File: stack_array.h
 * -------------------
 * This file exports a template version of the Stack class, using a
 * dynamic array as the underlying representation.
 */

#include "error.h"

template <class T>
class Stack {
public:
    Stack();
    ~Stack();
    Stack(const Stack&);
    Stack& operator=(const Stack&);

    int size() const;
    bool empty() const;
    void clear();
    void push(T);
    T pop();
    T top() const;

private:
    static const int INITIAL_CAPACITY = 10;

    T *array;
    int capacity;
    int count;

    void deepcopy(const Stack&);
    void expandCapacity();
};

template <class T>
Stack<T>::Stack() {
    capacity = INITIAL_CAPACITY;
    array = new T[capacity];
    count = 0;
}

template <class T>
Stack<T>::~Stack() {
    delete[] array;
}

template <class T>
int Stack<T>::size() const {
    return count;
}

template <class T>
bool Stack<T>::empty() const {
    return count == 0;
}

template <class T>
void Stack<T>::clear() {
    size = 0;
}

template <class T>
void Stack<T>::push(T val) {
    if (count == capacity)
        expandCapacity();
    array[count++] = val;
}

template <class T>
T Stack<T>::pop() {
    if (empty())
        error("Attempting to pop an empty array.");
    return array[--count];
}

template <class T>
T Stack<T>::top() const {
    if (empty())
        error("Attempting to access the top element of an empty array.");
    return array[count - 1];
}

template <class T>
void Stack<T>::deepcopy(const Stack& src) {
    capacity = src.count + INITIAL_CAPACITY;
    this->array = new T[capacity];
    for (int i = 0; i != capacity; ++i)
        array[i] = src.array[i];
    count = src.count;
}

template <class T>
void Stack<T>::expandCapacity() {
    T *oldArray = array;
    capacity *= 2;
    array = new T[capacity];
    for (int i = 0; i != capacity; ++i)
        array[i] = oldArray[i];
    delete[] oldArray;
}

template <class T>
Stack<T>::Stack(const Stack<T>& rhs) {
    deepcopy(rhs);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rhs) {
    if (this != &rhs) {
        delete[] array;
        deepcopy(rhs);
    }
    return *this;
}


#endif // STACK_ARRAY_H
