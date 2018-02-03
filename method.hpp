#ifndef METHOD_HPP
#define METHOD_HPP
#include <string>

#include "quicksort.hpp"
#include "radixsort.hpp"

void printMenu();

void q12Menu();

void q3Menu();

void q4Menu();

void q5Menu();

void test(QuickSort* quickSort, RadixSort* radixSort);

void question12(QuickSort* quickSort, RadixSort* radixSort);

void question3(QuickSort* quickSort, RadixSort* radixSort);

void question4(QuickSort* quickSort, RadixSort* radixSort);

void question5(QuickSort* quickSort, RadixSort* radixSort);

void generateRandomArray(int arr[], int SIZE);

void reverseArray(int arr[], int SIZE);

void readGuide();

template<class ItemType>
void testSort(ItemType* sorting, int arr[], int SIZE);

void testSortByArraySize(QuickSort* quickSort, RadixSort* radixSort, int SIZE);

void testSortByPivot(QuickSort* quickSort, int arr[], int SIZE, string type);

void testSortByCase(QuickSort* quickSort, RadixSort* radixSort, string type);

#endif // METHOD_HPP
