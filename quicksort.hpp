#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

class QuickSort{
    private:

    public:
        QuickSort();

        void sort(int arr[], int size);

        // A utility function to swap two elements
        void swap(int* a, int* b);

        //This function takes last element as pivot, places
        //the pivot element at its correct position in sorted
        //array, and places all smaller (smaller than pivot)
        //to left of pivot and all greater elements to right
        //of pivot
        int partition(int arr[], int low, int high, int size);

        // Generates Random Pivot, swaps pivot with
        // end element and calls the partition function
        int partition_r(int arr[], int low, int high, int size);

        //The main function that implements QuickSort
        //arr[] --> Array to be sorted,
        //low  --> Starting index,
        //high  --> Ending index
        void quickSort(int arr[], int low, int high, int size);

        //The main function for random pivot that implements QuickSort
        //arr[] --> Array to be sorted,
        //low  --> Starting index,
        //high  --> Ending index
        void quickSort_r(int arr[], int low, int high, int size);

        // Function to print an array
        void printArray(int arr[], int size);

        // Destructor
        ~QuickSort();
};

#endif // QUICKSORT_HPP
