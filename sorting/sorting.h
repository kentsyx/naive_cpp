/* File: sorting.h
 * ---------------
 * This file exports the interface of some classic sorting algorithms.
 */

#ifndef SORTING_H
#define SORTING_H

#include <vector>

void selectionSort(std::vector<int>&);

void mergeSort(std::vector<int>&);
void merge(std::vector<int>&, std::vector<int>&, std::vector<int>&);

void quickSort(std::vector<int>&, int, int);
int partition(std::vector<int>&, int, int);

#endif // SORTING_H
