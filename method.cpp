#include <cstdlib>
#include <chrono> // C++11
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#include "method.hpp"

void printMenu(){
    cout << "********************************************"<< endl;
    cout << "*  Quick Sort & Radix Sort Driver Program  *"<< endl;
    cout << "********************************************"<< endl;
    cout << "1. Implementation of Quick Sort and Radix Sort with 20 elements" << endl;
    cout << "2. Implementation of Quick Sort and Radix Sort with big array sizes" << endl;
    cout << "3. Implementation of Quick Sort using different pivot" << endl;
    cout << "4. Implementation of Quick Sort and Radix Sort with different cases" << endl;
    cout << "5. Guide" << endl;
    cout << "100. Quit Program." << endl;

    return;
}

void q12Menu(){
    cout << "-------------------------" << endl;
    cout << "| Question 1 and 2 Menu |" << endl;
    cout << "-------------------------" << endl;
    cout << "*Implementation of Quick Sort and Radix Sort with 20 elements*" << endl;
    cout << "1. Quick Sort" << endl;
    cout << "2. Radix Sort" << endl;
    cout << "100. Return to Main Menu." << endl;

    return;
}

void q3Menu(){
    cout << "-------------------------" << endl;
    cout << "|    Question 3 Menu    |" << endl;
    cout << "-------------------------" << endl;
    cout << "*Implementation of Quick Sort and Radix Sort with big array sizes*" << endl;
    cout << "1. Array Size 10,000" << endl;
    cout << "2. Array Size 100,000" << endl;
    cout << "3. Array Size 1,000,000" << endl;
    cout << "100. Return to Main Menu." << endl;

    return;
}

void q4Menu(){
    cout << "-------------------------" << endl;
    cout << "|    Question 4 Menu    |" << endl;
    cout << "-------------------------" << endl;
    cout << "*Implementation of Quick Sort using different pivot*" << endl;
    cout << "1. Random Pivot (Quick Sort)" << endl;
    cout << "2. Fixed Pivot (Quick Sort)" << endl;
    cout << "100. Return to Main Menu." << endl;

    return;
}

void q5Menu(){
    cout << "-------------------------" << endl;
    cout << "|    Question 5 Menu    |" << endl;
    cout << "-------------------------" << endl;
    cout << "*Implementation of Quick Sort and Radix Sort with different cases*" << endl;
    cout << "1. Quick Sort - Best Case, Average Case, Worst Case" << endl;
    cout << "2. Radix Sort - Best Case, Average Case, Worst Case" << endl;
    cout << "100. Return to Main Menu." << endl;

    return;
}

void test(QuickSort* quickSort, RadixSort* radixSort){
    int option;
    bool done = false;
    do
    {
        system("cls");
        printMenu();
        cout << "\nEnter your option: ";
        cin >> option;

        //Check input
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cerr << "Invalid input." << endl;
            cout << "Enter your option again: ";
            cin >> option;
        }

        switch(option)
        {
            case 1:
                system("cls");
                // test quick sort with 20 numbers
                question12(quickSort, radixSort);
                break;
            case 2:
                system("cls");
                // test both with different array size
                question3(quickSort, radixSort);
                break;
            case 3:
                system("cls");
                // test quick sort with random pivot and fixed pivot
                question4(quickSort, radixSort);
                break;
            case 4:
                system("cls");
                // test both with different case (best, average, worst)
                question5(quickSort, radixSort);
                break;
            case 5:
                system("cls");
                // print guide
                readGuide();
                break;
            case 100:
                done = true;
                break;
            default:
                cerr << "Invalid option. Select above options only. " << endl;
        }
        cout << endl;
        system("pause");
    } while (!done);

    cout << "\nThank you for using the program." << endl;

    return;
}

void question12(QuickSort* quickSort, RadixSort* radixSort){
    int option;
    bool done = false;

    // generate array with size 20
    int SIZE = 20;
    int* arr = new int[SIZE];
    generateRandomArray(arr, SIZE);
    int* copiedArray = new int[SIZE];
    copy(arr, arr+SIZE, copiedArray);

    do
    {
        system("cls");
        q12Menu();
        cout << "\nEnter your option: ";
        cin >> option;

        //check input
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cerr << "Invalid input." << endl;
            cout << "Enter your option again: ";
            cin >> option;
        }
        //End check input

        switch(option)
        {
            case 1:
                system("cls");
                testSort(quickSort, arr, SIZE);
                cout << endl;
                system("pause");
                break;
            case 2:
                system("cls");
                testSort(radixSort, copiedArray, SIZE);
                cout << endl;
                system("pause");
                break;
            case 100:
                done = true;
                break;
            default:
                cerr << "Invalid option. Select above options only. " << endl;
        }
    } while (!done);

    delete [] arr;
    delete [] copiedArray;

    return;
}

void question3(QuickSort* quickSort, RadixSort* radixSort){
    int option;
    bool done = false;
    do
    {
        system("cls");
        q3Menu();
        cout << "\nEnter your option: ";
        cin >> option;

        //check input
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cerr << "Invalid input." << endl;
            cout << "Enter your option again: ";
            cin >> option;
        }
        //End check input

        switch(option)
        {
            case 1:
                system("cls");
                testSortByArraySize(quickSort, radixSort, 10000);
                cout << endl;
                system("pause");
                break;
            case 2:
                system("cls");
                testSortByArraySize(quickSort, radixSort, 100000);
                cout << endl;
                system("pause");
                break;
            case 3:
                system("cls");
                testSortByArraySize(quickSort, radixSort, 1000000);
                cout << endl;
                system("pause");
                break;
            case 100:
                done = true;
                break;
            default:
                cerr << "Invalid option. Select above options only. " << endl;
        }
    } while (!done);

    return;
}

void question4(QuickSort* quickSort, RadixSort* radixSort){
    int option;
    bool done = false;

    // generate array with size 20
    int SIZE = 20;
    int* arr = new int[SIZE];
    generateRandomArray(arr, SIZE);
    int* copiedArray = new int[SIZE];
    copy(arr, arr+SIZE, copiedArray);

    do
    {
        system("cls");
        q4Menu();
        cout << "\nEnter your option: ";
        cin >> option;

        //check input
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cerr << "Invalid input." << endl;
            cout << "Enter your option again: ";
            cin >> option;
        }
        //End check input

        switch(option)
        {
            case 1:
                system("cls");
                testSortByPivot(quickSort, arr, SIZE, "random");
                cout << endl;
                system("pause");
                break;
            case 2:
                system("cls");
                testSortByPivot(quickSort, copiedArray, SIZE, "fixed");
                cout << endl;
                system("pause");
                break;
            case 100:
                done = true;
                break;
            default:
                cerr << "Invalid option. Select above options only. " << endl;
        }
    } while (!done);

    delete [] arr;
    delete [] copiedArray;

    return;
}

void question5(QuickSort* quickSort, RadixSort* radixSort){
    int option;
    bool done = false;
    do
    {
        system("cls");
        q5Menu();
        cout << "\nEnter your option: ";
        cin >> option;

        //check input
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(1000,'\n');
            cerr << "Invalid input." << endl;
            cout << "Enter your option again: ";
            cin >> option;
        }
        //End check input

        switch(option)
        {
            case 1:
                system("cls");
                testSortByCase(quickSort, radixSort, "quick");
                cout << endl;
                system("pause");
                break;
            case 2:
                system("cls");
                testSortByCase(quickSort, radixSort, "radix");
                cout << endl;
                system("pause");
                break;
            case 100:
                done = true;
                break;
            default:
                cerr << "Invalid option. Select above options only. " << endl;
        }
    } while (!done);

    return;
}

void generateRandomArray(int arr[], int SIZE){
    srand(time(0));
    for(int i=0;i<SIZE;i++){
        arr[i] = random(SIZE);
    }

    return;
}

int random(int SIZE){
    if ((SIZE > 0) && (SIZE <= 100)){
        return randomInt(10) + 10 * randomInt(10);
    }
    if ((SIZE > 100) && (SIZE <= 1000)){
        return randomInt(10) + 10 * randomInt(10) + 100 * randomInt(10);
    }
    if ((SIZE > 1000) && (SIZE <= 10000)){
        return randomInt(10) + 10 * randomInt(10) + 100 * randomInt(10) + 1000 * randomInt(10);
    }
    if ((SIZE > 10000) && (SIZE <= 100000)){
        return randomInt(10) + 10 * randomInt(10) + 100 * randomInt(10) + 1000 * randomInt(10) + 10000 * randomInt(10);
    }
    if ((SIZE > 100000) && (SIZE <= 1000000)){
        return randomInt(10) + 10 * randomInt(10) + 100 * randomInt(10) + 1000 * randomInt(10) + 10000 * randomInt(10) + 100000 * randomInt(10);
    }
    if (SIZE > 10000000) {
        return randomInt(10) + 10 * randomInt(10) + 100 * randomInt(10) + 1000 * randomInt(10) + 10000 * randomInt(10) + 100000 * randomInt(10) + 1000000 * randomInt(10);
    }
    return 0;
}

int randomInt(int upperLimit){
    int const limit = (RAND_MAX + 1) - (RAND_MAX + 1) % upperLimit;
    int result = rand();
    while ( result >= limit )
        result = rand();

    return result % upperLimit;
}

void reverseArray(int arr[], int SIZE){
    for (int i=0;i<SIZE/2;i++){
        int temp = arr[i];
        arr[i] = arr[(SIZE-1)-i];
        arr[(SIZE-1)-i] = temp;
    }
}

void readGuide(){
    ifstream readMenuGuide;
    readMenuGuide.open("guide.txt");
    if(readMenuGuide.fail())
    {
        cout << "Input file opening fail." << endl;
        return;
    }
    else
    {
        cin.ignore(1000,'\n');
        string next;
        while(!readMenuGuide.eof())
        {
            getline(readMenuGuide,next);
            cout << next << endl;
        }
    }
    readMenuGuide.close();

    return;
}

template<class ItemType>
void testSort(ItemType* sorting, int arr[], int SIZE){
    if (SIZE<=100){
        cout << "Initial Array: ";
        sorting->printArray(arr, SIZE);
        cout << endl;
    }

    auto start = chrono::system_clock::now();
    sorting->sort(arr, SIZE);
    auto end = chrono::system_clock::now();
    chrono::duration<double> duration = end - start;

    // print sorted array
    if (SIZE<=100){
        cout << "Sorted Array: ";
        sorting->printArray(arr, SIZE);
        cout << endl;
    }

    double bigduration = duration.count() * 1000;

    cout << "Duration: " << bigduration << " ms\n";

    return;
}

void testSortByArraySize(QuickSort* quickSort, RadixSort* radixSort, int SIZE){
    // generate array by size
    int* arr = new int[SIZE];
    generateRandomArray(arr, SIZE);
    int* copiedArray = new int[SIZE];
    copy(arr, arr+SIZE, copiedArray);

    cout << "Quick Sort" << endl;
    cout << "----------" << endl;
    testSort(quickSort, arr, SIZE);
    cout << "-----------------------This is a partition-----------------------\n" << endl;
    cout << "Radix Sort" << endl;
    cout << "----------" << endl;
    testSort(radixSort, copiedArray, SIZE);
    cout << "-----------------------This is a partition-----------------------\n" << endl;

    delete [] arr;
    delete [] copiedArray;

    return;
}

void testSortByPivot(QuickSort* quickSort, int arr[], int SIZE, string type){
    if (type=="random"){
        cout << "Random Pivot" << endl;
        cout << "------------" << endl;
        cout << "Initial Array: ";
        quickSort->printArray(arr, SIZE);
        cout << endl;

        auto start = chrono::system_clock::now();
        quickSort->quickSort_r(arr, 0, SIZE-1, SIZE);
        auto end = chrono::system_clock::now();
        chrono::duration<double> duration = end - start;

        // print sorted array
        cout << "Sorted Array: ";
        quickSort->printArray(arr, SIZE);
        cout << endl;

        double bigduration = duration.count() * 1000;

        cout << "Duration: " << bigduration << " ms\n";
        cout << "-----------------------This is a partition-----------------------\n" << endl;
    }
    else if (type=="fixed"){
        cout << "Fixed Pivot" << endl;
        cout << "-----------" << endl;
        testSort(quickSort, arr, SIZE);
        cout << "-----------------------This is a partition-----------------------\n" << endl;
    }
    else{
        cerr << "error: undefined pivot type" << endl;
    }

    return;
}

void testSortByCase(QuickSort* quickSort, RadixSort* radixSort, string type){
    if (type=="quick"){
        // best case - quick sort
        int arr[] = {1,3,5,6,9,10,13,12,14,11,15,7,2,4,8};
        int SIZE = sizeof(arr)/sizeof(arr[0]);

        cout << "Quick Sort - Best Case" << endl;
        cout << "----------------------" << endl;
        testSort(quickSort, arr, SIZE);
        cout << "-----------------------This is a partition-----------------------\n" << endl;

        // average case - quick sort
        int arr2[] = {1,3,5,7,9,11,13,15,14,12,10,8,6,4,2};
        random_shuffle(begin(arr2),end(arr2));
        int SIZE2 = sizeof(arr2)/sizeof(arr2[0]);

        cout << "Quick Sort - Average Case" << endl;
        cout << "-------------------------" << endl;
        testSort(quickSort, arr2, SIZE2);
        cout << "-----------------------This is a partition-----------------------\n" << endl;

        // worst case - quick sort
        int arr3[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
        int SIZE3 = sizeof(arr3)/sizeof(arr3[0]);

        cout << "Quick Sort - Worst Case" << endl;
        cout << "-----------------------" << endl;
        testSort(quickSort, arr3, SIZE3);
        cout << "-----------------------This is a partition-----------------------\n" << endl;

    }
    else if (type=="radix"){
        // best case - radix sort
        int arr[] = {1,2,3,4,5,6,7,8,9,1};
        int SIZE = sizeof(arr)/sizeof(arr[0]);

        cout << "Radix Sort - Best Case" << endl;
        cout << "----------------------" << endl;
        testSort(radixSort, arr, SIZE);
        cout << "-----------------------This is a partition-----------------------\n" << endl;

        // average case - radix sort
        int arr2[] = {100,200,300,400,5000,6000,7000,8000,90000,90000};
        int SIZE2 = sizeof(arr2)/sizeof(arr2[0]);

        cout << "Radix Sort - Average Case" << endl;
        cout << "-------------------------" << endl;
        testSort(radixSort, arr2, SIZE2);
        cout << "-----------------------This is a partition-----------------------\n" << endl;

        // worst case - radix sort
        int arr3[] = {1,20,300,4000,50000,600000,7000000,80000000,900000000,1000000000};
        int SIZE3 = sizeof(arr3)/sizeof(arr3[0]);

        cout << "Radix Sort - Worst Case" << endl;
        cout << "-----------------------" << endl;
        testSort(radixSort, arr3, SIZE3);
        cout << "-----------------------This is a partition-----------------------\n" << endl;
    }
    else {
        cerr << "error: undefined case type" << endl;
    }

    return;
}
