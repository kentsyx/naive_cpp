/* File: array_list.h
 * ------------------
 * This file exports the template version of the Stack class, implements
 * the underlying representation using a linked list.
 */


#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

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
    T top();

private:
    struct Cell{
        Cell *link;
        T data;
    };

    Cell *list; /* initial pointer in the stack */
    int count; /* number of cells in the stack */

    void deepcopy(const Stack&);
};

template <class T>
Stack<T>::Stack() {
    list = nullptr;
    count = 0;
}

template <class T>
Stack<T>::~Stack() {
    clear();
}

template <class T>
Stack<T>::Stack(const Stack& src) {
    deepcopy(src);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs) {
    if (this != &rhs) {
        clear();
        deepcopy(rhs);
    }
    return *this;
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
    while (count > 0)
        pop();
}

template <class T>
void Stack<T>::push(T val) {
    Cell *cp = new Cell;
    cp->data = val;
    cp->link = list;
    list = cp;
    count++;
}

template <class T>
T Stack<T>::pop() {
    if (empty())
        error("Attempting to pop an empty array.");
    Cell *cp = list;
    T result = cp->data;
    list = list->link;
    delete cp;
    count--;
    return result;
}

template <class T>
T Stack<T>::top() {
    if (empty())
        error("Attempting to access the first element in an empty array.");
    return list->data;
}

template <class T>
void Stack<T>::deepcopy(const Stack& src) {
    count = src.count;
    Cell *tail = nullptr;
    for (Cell *cp = src.list; cp != nullptr; cp = cp->link) {
        Cell *ncp = new Cell;
        ncp->data = cp->data;
        if (tail == nullptr) {
            list = ncp;
        } else {
            tail->link = ncp;
        }
        tail = ncp;
    }
    if (tail != nullptr)
        tail->link = nullptr;
}

#endif // ARRAY_LIST_H
