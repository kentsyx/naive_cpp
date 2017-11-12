/* File: queue.h
 * -------------
 * This interface exports the template version of the Queue class
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "error.h"

template <class T>
class Queue {
public:
    Queue();
    Queue(const Queue&);
    Queue<T> operator=(const Queue&);
    ~Queue();

    int size() const;
    bool empty() const;
    void clear();
    void enqueue(T);
    T dequeue();
    T top() const;

private:
    static const int INITIAL_CAPACITY = 10;

    T *array;
    int capacity;
    int head;
    int tail;

    void deepCopy(const Queue&);
    void expandCapacity();

};


template <class T>
Queue<T>::Queue() {
    capacity = INITIAL_CAPACITY;
    array = new T[capacity];
    head = 0;
    tail = 0;
}

template <class T>
Queue<T>::Queue(const Queue& src) {
    deepCopy(src);
}

template <class T>
Queue<T>::~Queue() {
    delete[] array;
}

template <class T>
Queue<T> Queue<T>::operator=(const Queue& rhs) {
    if (this != &rhs) {
        delete[] array;
        deepCopy(rhs);
    }
    return *this;
}

template <class T>
int Queue<T>::size() const {
    return (tail + capacity - head) % capacity;
}

template <class T>
bool Queue<T>::empty() const {
    return head == tail;
}

template <class T>
void Queue<T>::clear() {
    head = tail = 0;
}

template <class T>
void Queue<T>::enqueue(T val) {
    if (size() == capacity - 1)
        expandCapacity();
    array[tail] = val;
    tail = (tail + 1) % capacity;
}

template <class T>
T Queue<T>::dequeue() {
    if (empty())
        error("Attempting to dequeue an empty queue.");
    T result = array[head];
    head = (head + 1) % capacity;
    return result;
}

template <class T>
T Queue<T>::top() const {
    if (empty())
        error("Attempting to top an empty queue.");
    return array[head];
}

template <class T>
void Queue<T>::deepCopy(const Queue& src) {
    int count = src.size();
    capacity = count + INITIAL_CAPACITY;
    array = new T[capacity];
    for (int i = 0; i != count; ++i)
        array[i] = src.array[(src.head + i) % src.capacity];
    head = 0;
    tail = count;
}

template <class T>
void Queue<T>::expandCapacity() {
    int count = size();
    T *oldArray = array;
    array = new T[capacity * 2];
    for (int i = 0; i != count; ++i)
        array[i] = oldArray[(head + i) % capacity];
    capacity *= 2;
    head = 0;
    tail = count;
    delete[] oldArray;
}

#endif // QUEUE_H
