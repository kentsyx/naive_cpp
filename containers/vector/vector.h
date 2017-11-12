/* File: vector.h
 * --------------
 * This interface exports the template Vector class, which provides a efficient,
 * safe and convenient replacement for the array type in C++
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "error.h"

template <class T>
class Vector {

public:
    Vector();
    Vector(const Vector<T>&);
    Vector(int, T);
    ~Vector();
    Vector<T>& operator=(const Vector<T>&);
    T& operator[](int);

    int size() const;
    bool empty() const;
    void clear();
    int get(T) const; /* returns the index of the element */
    void insert(int, T);
    void push_back(T);
    void remove(int);

private:
    static const int INITIAL_CAPACITY = 10;
    T *array;
    int capacity;
    int count;

    void deepCopy(const Vector<T>&);
    void expandCapacity();

};

template <class T>
Vector<T>::Vector() {
    capacity = INITIAL_CAPACITY;
    array = new T[capacity];
    count = 0;
}

template <class T>
Vector<T>::Vector(const Vector<T>& src) {
    deepCopy(src);
}

template <class T>
Vector<T>::Vector(int n, T val) {
    capacity = (n > capacity) ? n : capacity;
    for (int i = 0; i != n; ++i)
        array[i] = val;
    count = n;
}

template <class T>
Vector<T>::~Vector() {
    delete[] array;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {
    if (this != &rhs) {
        delete[] array;
        deepCopy(rhs);
    }
    return *this;
}

template <class T>
T& Vector<T>::operator[](int idx) {
    return array[idx];
}

template <class T>
int Vector<T>::size() const {
    return count;
}

template <class T>
bool Vector<T>::empty() const {
    return count == 0;
}

template <class T>
void Vector<T>::clear() {
    count = 0;
}

template <class T>
void Vector<T>::insert(int idx, T val) {
    if (count == capacity)
        expandCapacity();
    if (idx < 0 || idx > count)
        error("Index out of range.");
    for (int i = count; i != idx; --i)
        array[i] = array[i - 1];
    array[idx] = val;
    count++;
}

template <class T>
void Vector<T>::push_back(T val) {
    insert(count, val);
}

template <class T>
void Vector<T>::remove(int idx) {
    if (idx < 0 || idx >= count)
        error("Index out of range.");
    for (int i = idx; i != count - 1; )
        array[i] = array[i + 1];
    count--;
}

template <class T>
void Vector<T>::deepCopy(const Vector<T>& src) {
    capacity = src.count + INITIAL_CAPACITY;
    this->array = new T[capacity];
    for (int i = 0; i != src.count; ++i)
        array[i] = src.array[i];
    count = src.count;
}

template<class T>
void Vector<T>::expandCapacity() {
    T *oldArray = array;
    capacity *= 2;
    array = new T[capacity];
    for (int i = 0; i != count; ++i)
        array[i] = oldArray[i];
    delete[] array;
}

#endif // VECTOR_H
