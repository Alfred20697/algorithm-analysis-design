#include <iostream>
using namespace std;

#include "radixsort.hpp"

RadixSort::RadixSort(){

}

void RadixSort::sort(int arr[], int size){
    radixsort(arr, size);

    return;
}

int RadixSort::getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];

    return mx;
}

void RadixSort::radixsort(int arr[], int n){
    // Find the maximum number to know number of digits
    int maxNumber = getMax(arr, n);

    // run the loop for each decimal places
    int exp = 1;
    int *output = new int[n];
    while (maxNumber/exp>0){
        int decimalBucket[10] = {0};
        //count the occurrences int this decimal digit
        for (int i=0;i<n;i++){
            decimalBucket[arr[i]/exp%10]++;
        }

        // prepare the position counters to be used for re-ordering
        // the numbers for this decimal place
        for (int i=1;i<10;i++){
            decimalBucket[i] += decimalBucket[i-1];
        }

        // re order the numbers in the output and later copy back to
        // original array
        for (int i=n-1;i>=0;i--){
            output[--decimalBucket[arr[i]/exp%10]] = arr[i];
        }
        for (int i=0;i<n;i++){
            arr[i] = output[i];
        }

        if (n<=20){
            printArray(arr, n);
            cout << endl;
        }

        exp *= 10;
    }

    return;
}

void RadixSort::printArray(int arr[], int size){
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";

    return;
}

RadixSort::~RadixSort(){

}
