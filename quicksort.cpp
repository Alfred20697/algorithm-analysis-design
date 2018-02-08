#include <iostream>
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;

#include "quicksort.hpp"

QuickSort::QuickSort(){

}

void QuickSort::sort(int arr[], int size){
    quickSort(arr, 0, size-1, size);

    return;
}

void QuickSort::swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;

    return;
}

int QuickSort::partition(int arr[], int low, int high, int size){
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    if (size<=20){
        printArray(arr, size);
        cout << "Pivot: " << pivot << endl;
    }

    return (i + 1);
}

int QuickSort::partition_r(int arr[], int low, int high, int size){
    // Generate a random number in between
    // low .. high
    srand(time(NULL));
    int random = low + rand() % (high - low);

    // Swap A[random] with A[high]
    swap(&arr[random], &arr[high]);

    return partition(arr, low, high, size);
}

void QuickSort::quickSort(int arr[], int low, int high, int size){
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high, size);

        // Separately sort elements before
        // partition and after partition
        //printArray(arr,20);
        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
        //printArray(arr,20);
    }

    return;
}

void QuickSort::quickSort_r(int arr[], int low, int high, int size){
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition_r(arr, low, high, size);

        // Separately sort elements before
        // partition and after partition
        //printArray(arr,20);
        quickSort(arr, low, pi - 1, size);
        quickSort(arr, pi + 1, high, size);
        //printArray(arr,20);
    }

    return;
}

void QuickSort::printArray(int arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";

    return;
}

QuickSort::~QuickSort(){

}
