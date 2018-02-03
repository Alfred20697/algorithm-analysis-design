#include <iostream>
using namespace std;

#include "radixsort.hpp"

RadixSort::RadixSort(){

}

void RadixSort::sort(int arr[], int size){
    cout << "Here 1" << endl;
    radixsort(arr, size);

    return;
}

int RadixSort::getMax(int arr[], int n){
    cout << "Here 3" << endl;
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    return mx;
}

void RadixSort::countSort(int arr[], int n, int exp){
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];

    if (n<=20){
        printArray(arr, n);
    }

    return;
}

void RadixSort::radixsort(int arr[], int n){
    cout << "Here 2" << endl;
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);

    return;
}

void RadixSort::printArray(int arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return;
}

RadixSort::~RadixSort(){

}
