/* File: hashmap.h
 * ---------------
 * This file exports the HashMap class, which stores a set of key-value pairs
 * and enables constant time look-up.
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <cstdlib>
#include <sstream>
#include <string>
#include "vector.h"
#include "hashfunc.h"

/* The below hashCode function is overloaded to support all
 * primitive types and the C++ string type
 */

int hashCode(const std::string&);
int hashCode(int);
int hashCode(char);
int hashCode(long);
int hashCode(double);

/* T: generic Key type
 * V: generic Value type
 */

template <class T, class V>
class HashMap {
    HashMap();
    virtual ~HashMap();

    int size() const;
    bool empty() const;
    void put(T, V);
    V get(T) const;
    bool contains(T) const;
    void remove(T);
    void clear();

    V& operator[](T);
    V operator[](T) const;

    std::string toString();

    void mapAll(void (*fn)(T, V)) const;
    void mapAll(void (*fn)(const T&, const V&)) const;

    template <class F>
    void mapAll(F fn) const;

private:

    static const int INITIAL_BUCKET_COUNT = 101;
    static const int MAX_LOAD_PERCENTAGE = 70;

    struct Cell {
        T key;
        V value;
        Cell *next;
    };

    Vector<Cell*> buckets;
    int nBuckets;
    int nEntries;

    void createBuckets(int);
    void deleteBuckets(Vector<Cell*>&);
    void expandAndRehash();

    Cell* findCell(int, T) const;
    Cell* findCell(int, T, Cell*&) const;

    void deepCopy();
};

template <class T, class V>
HashMap<T, V>::HashMap() {
    createBuckets(INITIAL_BUCKET_COUNT);
}

template <class T, class V>
HashMap<T, V>::~HashMap() {
    deleteBuckets(buckets);
}

template <class T, class V>
int HashMap<T, V>::size() const {
    return nEntries;
}

template <class T, class V>
bool HashMap<T, V>::empty() const {
    return size() == 0;
}

template <class T, class V>
void HashMap<T, V>::put(T key, V value) {
    (*this)[key] = value;
}

template <class T, class V>
V HashMap<T, V>::get(T key) const {
    Cell *cp = findCell(hashCode(key) % nBuckets, key);
    if (cp == nullptr)
        return V();
    return cp->value;
}

template <class T, class V>
bool HashMap<T, V>::contains(T key) const {
    return findCell(hashCode(key) % nBuckets, key) != nullptr;
}

template <class T, class V>
void HashMap<T, V>::remove(T key) {
    int bucket = hashCode(key) % nBuckets;
    Cell *parent;
    Cell *cp = findCell(bucket, key, parent);
    if (cp != nullptr) {
        if (parent == nullptr) {
            buckets[bucket] = cp->next;
        } else {
            parent->next = cp->next;
        }
        delete cp;
        nEntries--;
    }
}

template <class T, class V>
void HashMap<T, V>::clear() {
    deleteBuckets(buckets);
    nEntries = 0;
}

template <class T, class V>
V& HashMap<T, V>::operator[](T key) {
    int bucket = hashCode(key) % nBuckets;
    Cell *cp = findCell(bucket, key);
    if (cp == nullptr) {
        if (nEntries > MAX_LOAD_PERCENTAGE * nBuckets / 100.0) {
            expandAndRehash();
            bucket = hashCode(key) % nBuckets;
        }
        cp = new Cell;
        cp->key = key;
        cp->value = V();
        cp->next = buckets[bucket];
        buckets[bucket] = cp;
        nEntries++;
    }
    return cp->value;
}

template <class T, class V>
V HashMap<T, V>::operator[](T key) const {
    return get(key);
}

template <class T, class V>
void HashMap<T, V>::mapAll(void (*fn)(T, V)) const {
    for (int i = 0; i < buckets.size(); i++) {
        for (Cell *cp = buckets.get(i); cp != nullptr; cp = cp->next) {
            fn(cp->key, cp->value);
        }
    }
}

template <class T, class V>
void HashMap<T, V>::mapAll(void (*fn)(const T&, const V&)) const {
    for (int i = 0; i < buckets.size(); i++) {
        for (Cell *cp = buckets.get(i); cp != nullptr; cp = cp->next) {
            fn(cp->key, cp->value);
        }
    }
}

template <class T, class V>
template <class F>
void HashMap<T, V>::mapAll(F fn) const {
    for (int i = 0; i < buckets.size(); i++) {
        for (Cell *cp = buckets.get(i); cp != nullptr; cp = cp->next) {
            fn(cp->key, cp->value);
        }
    }
}

template <class T, class V>
void HashMap<T, V>::createBuckets(int nBuckets) {
    if (nBuckets == 0)
        nBuckets = 1;
    buckets = Vector<Cell*>(nBuckets, nullptr);
    this->nBuckets = nBuckets;
    nEntries = 0;
}

template <class T, class V>
void HashMap<T, V>::deleteBuckets(Vector<Cell*>& buckets) {
    for (int i = 0; i < buckets.size(); i++) {
        Cell *cp = buckets[i];
        while (cp != nullptr) {
            Cell *np = cp->next;
            delete cp;
            cp = np;
        }
        buckets[i] = nullptr;
    }
}

template <class T, class V>
std::string HashMap<T, V>::toString() {
    std::ostringstream os;
    os << *this;
    return os.str();
}

#endif // HASHTABLE_H
