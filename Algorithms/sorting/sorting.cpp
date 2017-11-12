/* File: sorting.cpp
 * -----------------
 * This file implements the sorting.h interface/
 */

#include <vector>
#include "sorting.h"

using std::vector;

/* Selection sort */

void selectionSort(vector<int>& vec) {
    int n = vec.size();
    for (int lh = 0; lh != n; ++lh) {
        int rh = lh;
        for (int i = lh + 1; i != n; ++i) {
            if (vec[i] < vec[rh])
                rh = i;
        }
        int tmp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = tmp;
    }
}

/* Merge sort */

void mergeSort(vector<int>& vec) {
    int n = vec.size();
    if (n <= 1)
        return;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i != n; ++i) {
        if (i < n / 2)
            v1.push_back(vec[i]);
        else
            v2.push_back(vec[i]);
    }
    mergeSort(v1);
    mergeSort(v2);
    vec.clear();
    merge(vec, v1, v2);
}

void merge(vector<int>& vec, vector<int>& v1, vector<int>& v2) {
    /* vec should be an empty vector */
    int n1 = v1.size();
    int n2 = v2.size();
    int p1 = 0;
    int p2 = 0;
    while (p1 < n1 && p2 < n2) {
        if (v1[p1] <= v2[p2])
            vec.push_back(v1[p1++]);
        else
            vec.push_back(v2[p2++]);
    }
    while (p1 < n1)
        vec.push_back(v1[p1++]);
    while (p2 < n2)
        vec.push_back(v2[p2++]);
}

/* Quick sort */

void quickSort(vector<int>& vec, int start, int finish) {
    if (start >= finish)
        return;
    int boundary = partition(vec, start, finish);
    quickSort(vec, start, boundary - 1);
    quickSort(vec, boundary + 1, finish);
}

int partition(vector<int>& vec, int start, int finish) {
    int pivot = vec[start];
    int lh = start + 1;
    int rh = finish;
    while (true) {
        while (lh < rh && vec[rh] >= pivot)
            rh--;
        while (lh < rh && vec[lh] < pivot)
            lh++;
        if (lh == rh)
            break;
        int tmp = vec[lh];
        vec[lh] = vec[rh];
        vec[rh] = tmp;
    }
    if (pivot <= vec[lh])
        return start;
    vec[start] = vec[lh];
    vec[lh] = pivot;
    return lh;
}

