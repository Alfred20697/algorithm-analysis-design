#ifndef RADIXSORT_HPP
#define RADIXSORT_HPP

class RadixSort{
    private:

    public:
        RadixSort();

        void sort(int arr[], int size);

        // A utility function to get maximum value in arr[]
        int getMax(int arr[], int n);

        // The main function to that sorts arr[] of size n using
        // Radix Sort
        void radixsort(int arr[], int n);

        // Function to print an array
        void printArray(int arr[], int size);

        // Destructor
        ~RadixSort();
};

#endif // RADIXSORT_HPP
