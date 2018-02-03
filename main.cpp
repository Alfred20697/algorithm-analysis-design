#include <iostream>
using namespace std;

#include "quicksort.hpp"
#include "radixsort.hpp"
#include "method.hpp"

int main(){
    QuickSort* quickSort = new QuickSort();
    RadixSort* radixSort = new RadixSort();
    test(quickSort, radixSort);

    delete [] quickSort;
    delete [] radixSort;

    return 0;
}

