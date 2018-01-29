/* C++ implementation QuickSort */
#include <iostream>
#include <chrono> // C++11
#include <cstdlib>
using namespace std;

//to compile
// g++ -std=c++11 -c filename.cpp
// g++ -o filename filename.o
// g++ filename

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int partition (int arr[], int low, int high)
{
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
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver program to test above functions
int main()
{
    const int SIZE = 20;
    srand(time(0));
    int* arr = new int[SIZE];
    for(int i=0;i<SIZE;i++){
        arr[i] = rand() % 100;
    }

    // print initial array
    cout << "Initial Array: ";
    printArray(arr, SIZE);

    auto start = chrono::system_clock::now();
    quickSort(arr, 0, SIZE-1);
    auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "Sorted Array: ";
    printArray(arr, SIZE);

    cout << "Duration: " << duration.count() << "s\n";
    delete [] arr;

    return 0;
}
